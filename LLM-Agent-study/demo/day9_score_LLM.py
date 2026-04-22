import os
from openai import OpenAI


def extract_sections(text):
    parts = text.split("## ")
    sections = {}

    for part in parts[1:]:
        lines = part.splitlines()
        title = lines[0].strip().lower()
        body = "\n".join(lines[1:]).strip()

        if title in ["llm", "prompt", "rag", "tool", "agent"]:
            sections[title] = body

    return sections


def score_sections(question, sections):
    question = question.lower()

    keyword_map = {
        "llm": ["llm", "大模型", "大语言模型", "语言模型"],
        "prompt": ["prompt", "提示词", "提示语", "指令"],
        "rag": ["rag", "检索增强生成"],
        "tool": ["tool", "工具", "工具调用"],
        "agent": ["agent", "智能体", "代理", "代理系统"]
    }

    scores = {concept: 0 for concept in sections}

    for concept, aliases in keyword_map.items():
        for alias in aliases:
            if alias.lower() in question:
                scores[concept] += 1

    return scores


def find_best_section(question, sections):
    scores = score_sections(question, sections)

    best_section = None
    best_score = 0

    for concept, score in scores.items():
        if score > best_score:
            best_score = score
            best_section = concept

    if best_score == 0:
        return None, None, scores

    return best_section, sections[best_section], scores


def build_prompt(section_name, section_text, question):
    return f"""
你是一个严谨的学习助手。
请你只根据下面提供的学习笔记片段回答问题，不要使用片段之外的知识。
如果片段中没有明确答案，就直接回答：根据当前笔记片段，我无法确定。

【当前相关主题】
{section_name}

【学习笔记片段开始】
{section_text}
【学习笔记片段结束】

【用户问题】
{question}
""".strip()


def ask_llm(client, prompt):
    response = client.chat.completions.create(
        model="deepseek-chat",
        messages=[
            {"role": "system", "content": "你是一个严谨的学习助手。"},
            {"role": "user", "content": prompt}
        ],
        stream=False
    )
    return response.choices[0].message.content.strip()


with open("day1_basic_concepts.md", "r", encoding="utf-8") as f:
    notes = f.read()

sections = extract_sections(notes)

client = OpenAI(
    api_key=os.getenv("DEEPSEEK_API_KEY"),
    base_url="https://api.deepseek.com"
)

while True:
    question = input("请输入您的问题（输入 exit 退出）：").strip()

    if question.lower() in ["exit", "quit"]:
        print("退出程序")
        break

    if not question:
        print("问题不能为空")
        continue

    section_name, section_text, scores = find_best_section(question, sections)

    if section_text is None:
        print("我暂时无法判断你在问哪一节。")
        print(f"本次打分结果：{scores}\n")
        continue

    prompt = build_prompt(section_name, section_text, question)
    answer = ask_llm(client, prompt)

    print(f"\n本次打分结果：{scores}")
    print(f"匹配到的主题：{section_name.upper()}")
    print("回答如下：\n")
    print(answer)
    print()