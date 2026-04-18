###平常多使用C++，这篇旨在熟悉一下Python###
title = "LLM 学习笔记"
day = 2
notes = ["LLM 是语言模型", "RAG 是先检索再回答", "Agent会调用工具"]

print(title)
print(f"今天是第 {day} 课")
print(notes[0])

keywords= {
    "LLM" : "大语言模型",
    "RAG" : "检索增强生成",
    "Agent" : "智能体"
}

for key,value in keywords.items():
    print(f"{key} 的意思是 {value}")

with open("day1_basic_concepts.md","r",encoding="utf-8") as f:
    content =f.read()

print("文件内容如下")
print(content)

print("字符总数",len(content))

if "Agent" in content:
    print("文件中提到了 Agent")
else:
    print("文件中没有提到 Agent")

def count_keyword(text, keyword):
    return text.count(keyword)
agent_count = count_keyword(content, "Agent")
print(f"文件中 'Agent' 出现了 {agent_count} 次")
