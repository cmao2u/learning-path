with open("day1_basic_concepts.md",  "r", encoding="utf-8") as f:
    content = f.read()

def extract_sections(text):
    parts = text.split("## ")
    sections = {}

    for part in parts[1:]:
        lines = part.splitlines()
        title = lines[0].strip().lower()
        body = "\n".join(lines[1:]).strip()

        if title in ["llm", "prompt", "tool", "rag", "agent"]:
            sections[title] = body

    return sections

def answer_questions(question, sections):
    question =question.lower()

    for keyword in ["llm", "prompt", "tool", "rag", "agent"]:
        if keyword in question:
            if keyword in sections:
                return f"你问的是 {keyword.upper()}: \n{sections[keyword]}"
            else:
                return f"抱歉，我没有找到关于 {keyword.upper()} 的信息。"
    return "抱歉，我无法回答你的问题。"
sections = extract_sections(content)

user_question = input("请输入您的问题: ")
result=answer_questions(user_question, sections)

print("回答如下:\n")
print(result)