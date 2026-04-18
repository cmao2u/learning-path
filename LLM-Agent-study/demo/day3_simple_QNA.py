with open("day1_basic_concepts.md", "r", encoding="utf-8") as f:
    content=f.read()

def answer_question(question, text):
    question =question.lower()

    if "llm" in question:
        return "你问的是LLM\n\n" + text
    elif "rag" in question:
        return "你问的是RAG\n\n" + text
    elif "agent" in question:
        return "你问的是Agent\n\n" + text
    elif "prompt" in question:
        return "你问的是 Prompt\n\n" + text
    else:
        return "抱歉，我暂时不知道你问的是哪个概念"

user_question = input("请输入你的问题: ") 
result =answer_question(user_question,  content)

print("\n回答如下:")
print(result)
