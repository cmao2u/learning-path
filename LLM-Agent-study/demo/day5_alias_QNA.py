with open("day1_basic_concepts.md", "r", encoding = "utf-8") as f:
    content = f.read()

def extract_sections(content):
    parts = content.split("## ")
    sections = {}

    for part in parts[1:]:
        lines = part.splitlines()
        title = lines[0].strip().lower()
        body = "\n".join(lines[1:]).strip()

        if title in ["llm", "prompt", "tool", "rag", "agent"]:
            sections[title] = body
        
    return sections

def answer_questions(question,sections):
    question = question.lower()

    keyword_map = {
        "llm":["llm", "大语言模型", "大模型"],
        "prompt": ["prompt", "提示词"],
        "tool": ["tool", "工具"],
        "rag": ["rag", "检索增强生成"],
        "agent": ["agent", "智能体"]
    }
    for concept, aliases in keyword_map.items():
        for alias in aliases:
            if alias in question:
                if concept in sections:
                    return f"你问的是 {concept.upper()}, \n\n{sections[concept]}"
                else:
                    return f"找到了概念 {concept.upper()}, 但没有相关内容。"
    
    return "抱歉，我无法理解你的问题。请尝试使用与LLM、Prompt、Tool、RAG或Agent相关的关键词。"

sections = extract_sections(content)

while True:
    user_question = input("请输入您的问题: ")
    if(user_question.lower() in ["exit", "quit"]):
        print("退出程序。")
        break
    answer = answer_questions(user_question, sections)
    print("回答如下： \n")
    print(answer)