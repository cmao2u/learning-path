import os
from openai import OpenAI

with open("day1_basic_concepts.md", "r", encoding="utf-8") as f:
    notes = f.read()

client = OpenAI(
    api_key=os.getenv("DEEPSEEK_API_KEY"),
    base_url="https://api.deepseek.com"
)

question = input("请输入你的问题：")

prompt = f"""
你是一个严谨的学习助手。
请你只根据下面提供的学习笔记回答问题，不要使用笔记之外的知识。
如果笔记中没有明确答案，就直接回答：根据当前笔记，我无法确定。

【学习笔记开始】
{notes}
【学习笔记结束】

【用户问题】
{question}
""".strip()

response = client.chat.completions.create(
    model="deepseek-chat",
    messages=[
        {"role": "system", "content": "你是一个严谨的学习助手。"},
        {"role": "user", "content": prompt}
    ],
    stream=False
)

print("\n回答如下：\n")
print(response.choices[0].message.content)