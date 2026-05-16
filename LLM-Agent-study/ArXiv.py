import arxiv
import pandas as pd

query = '"retrieval-augmented generation" AND "vulnerability detection"OR"retrieval-augmented generation" AND "software vulnerability" OR "retrieval-augmented generation" AND "vulnerability repair"'

client = arxiv.Client()

search = arxiv.Search(
    query=query,
    max_results=50,
    sort_by=arxiv.SortCriterion.Relevance
)

papers = []

for result in client.results(search):
    papers.append({
        "title": result.title,
        "year": result.published.year,
        "authors": ", ".join(author.name for author in result.authors),
        "url": result.entry_id,
        "summary": result.summary.replace("\n", " ")
    })

df = pd.DataFrame(papers)
df.to_excel("arxiv_results.xlsx", index=False)

print(f"保存了 {len(papers)} 条结果到 arxiv_results.xlsx")