# RAG Vulnerability Literature Screening Report

Generated on 2026-05-10.

## 数据读取概况

| Database | Records extracted | Access status |
| --- | ---: | --- |
| IEEE Xplore | 169 | File read successfully |
| Springer Nature | 1000 | File read successfully |
| ACM Digital Library | 0 | Inaccessible |
| arXiv | 68 | Fetched saved HTML successfully |
| Google Scholar | 10 | Fetched first page HTML successfully |

## 无法读取或受限来源

| Database | URL/File | Notes |
| --- | --- | --- |
| ACM Digital Library | https://dl.acm.org/action/doSearch?AllField=%28%22retrieval-augmented+generation%22+OR+%22retrieval+augmented+generation%22++OR+%22RAG%22++OR+%22retrieval-augmented%22+OR+%22retrieval+augmented%22++OR+%22retrieval-enhanced+generation%22+OR+%22retrieval+enhanced+generation%22++OR+%22knowledge-augmented+generation%22+OR+%22knowledge+augmented+generation%22%29+AND+%28vulnerab*++OR+%22software+vulnerability%22+OR+%22code+vulnerability%22++OR+%22vulnerability+detection%22+OR+%22vulnerability+assessment%22++OR+%22vulnerability+analysis%22+OR+%22vulnerability+understanding%22++OR+%22vulnerability+repair%22+OR+%22vulnerability+description%22++OR+%22patch+generation%22+OR+%22program+repair%22++OR+%22vulnerability+patch%22+OR+%22security+patch%22+OR+%22patch+presence%22++OR+%22API+misuse%22++OR+%22security+flaw%22+OR+%22security+bug%22++OR+CVE+OR+CWE++OR+%22smart+contract+vulnerability%22+OR+%22smart+contract+security%22%29 | HTTP 403 Forbidden when fetching provided URL; no visible records extracted. |

## 去重与初筛结果

- Total raw records extracted: 1247
- Total duplicates removed: 10
- Total deduplicated records: 1237
- Final Initial Include: 51
- Final Initial Maybe: 70
- Final Initial Exclude: 1116

## 主要排除原因

| Exclusion reason | Count |
| --- | ---: |
| Not RAG | 931 |
| Not software/code-related | 94 |
| Not vulnerability-related | 85 |
| Survey only | 6 |

## 需要人工复核的论文

以下列出所有 Final Initial Decision 为 Maybe，或 Confidence 为 Low 的记录。Springer Nature 导出不含摘要，因此相关标题通常保守标为 Maybe。

| Record_ID | Title | Year | Decision | Confidence | Notes |
| --- | --- | --- | --- | --- | --- |
| REC-0006 | Automated Vulnerability Repair Based on Retrieval-Augmented Generation | 2025 | Maybe | Medium |  |
| REC-0008 | Pungoe Pentest: Orchestration of Web Penetration Testing Tools with Assistance Based on Large Language Model (LLM) Pentest-AI and Retrieval-augmented Generation (RAG) | 2025 | Maybe | Medium |  |
| REC-0019 | AegisGuard: A Context-Aware Framework for Semantic Vulnerability Detection and Risk Stratification | 2026 | Maybe | Medium |  |
| REC-0028 | Phishing Email Detection Using Large Language Models: A Comparative Analysis of Standalone and Retrieval Augmented Generation Models | 2025 | Maybe | Medium |  |
| REC-0033 | Hallucination-aware Retrieval Augmented Generation with Evidence-based Semantic Clustering | 2026 | Maybe | Medium |  |
| REC-0038 | Framework for Constructing Knowledge Bases of Cybersecurity Compliance Standards Based on Retrieval-Augmented Generation | 2025 | Maybe | Medium |  |
| REC-0039 | Research on the LLM-Driven Vulnerability Detection System Using LProtector | 2024 | Maybe | Medium |  |
| REC-0040 | Demo: A Real-time Multi-Agent Network Attack Detection and Incident Response System | 2025 | Maybe | Medium |  |
| REC-0042 | Repairing Responsive Layout Failures Using Retrieval Augmented Generation | 2025 | Maybe | Medium |  |
| REC-0047 | Fake News Detection in Bangladesh Using GPT-4 with Retrieval-Augmented Generation | 2025 | Maybe | Medium |  |
| REC-0048 | Federated Prompt Tuning for News Framing: A Community-Aware Approach to Narrative Exploitability | 2025 | Maybe | Medium |  |
| REC-0050 | HypoSelectSimRAG-Enhancing Answer Accuracy in RAG via Multi-Path Self-Consistent Query Translation | 2025 | Maybe | Medium |  |
| REC-0055 | Prioritizing Vulnerability Assessment Items Using LLM Based on IoT Device Documentations | 2024 | Maybe | Medium |  |
| REC-0060 | PenAgent: A Retrieval-Augmented Multi-Agent Framework for Automated Penetration Testing | 2026 | Maybe | Medium |  |
| REC-0061 | Comparative Analysis of Advanced RAG Techniques using Mahabharata | 2025 | Maybe | Medium |  |
| REC-0065 | IntellBot: Retrieval Augmented LLM Chatbot for Cyber Threat Knowledge Delivery | 2024 | Maybe | Medium |  |
| REC-0067 | Agentic Graph-RAG: A Multi-Agent Framework for Robust, Decomposed Multi-Hop Reasoning | 2025 | Maybe | Medium |  |
| REC-0069 | Empowering IoT Security: Automated Identification of Standard Library Functions in RTOS Firmware with LLM and RAG | 2026 | Maybe | Medium |  |
| REC-0073 | RAG Certainty: Quantifying the Certainty of Context-Based Responses by LLMs | 2024 | Maybe | Medium |  |
| REC-0074 | Special Session: ThreatLens: LLM-guided Threat Modeling and Test Plan Generation for Hardware Security Verification | 2025 | Maybe | Medium |  |
| REC-0077 | Temperature-Diverse Agreement Fusion for Trust-Aware RAG: Novel Ensemble and Chunking Strategies | 2025 | Maybe | Medium |  |
| REC-0081 | LAMBDA: LLM-Assisted Malicious Bug Detection and Analysis in Hardware Designs | 2025 | Maybe | Medium |  |
| REC-0085 | Detecting Hate Speech against People with Disabilities in Social Media Comments using RAG-Enhanced LLMs, Fine-Tuning, and Prompt Engineering | 2025 | Maybe | Medium |  |
| REC-0094 | Code Prism: A Multi-Agent, Multi-LLM, Semantic Indexing Artifact for Regulatory Code Audits — A Design Science Research Study | 2025 | Maybe | Medium |  |
| REC-0096 | LASSO: LLM-Aided Security Property Generation for Assertion-based SoC Verification | 2025 | Maybe | Medium |  |
| REC-0097 | ExplainHM++: Explainable Harmful Meme Detection With Retrieval-Augmented Debate Between Large Multimodal Models | 2026 | Maybe | Medium |  |
| REC-0100 | Phishing Website Detection via Multimodal Learning and Retrieval-Augmented Reasoning | 2025 | Maybe | Medium |  |
| REC-0102 | SecFSM: Knowledge Graph-Guided LLMs for Generating Secure Verilog Code of Finite State Machine in SoCs | 2026 | Maybe | Medium |  |
| REC-0103 | AgentRepair: Multi-Agent, AST-Anchored, Retrieval-Augmented Program Repair for Cold-Start Environments | 2025 | Maybe | Medium |  |
| REC-0105 | From Reviewers' Lens: Understanding Bug Bounty Report Invalid Reasons with LLMs | 2025 | Maybe | Medium |  |
| REC-0118 | LLMGraph: Label-Free Detection Against APTs in Edge Networks via LLM and GCN | 2025 | Maybe | Medium |  |
| REC-0119 | Design of Cybersecurity Knowledge Graph Systems Based on Large Language Models | 2025 | Maybe | Medium |  |
| REC-0137 | Ratchet: Retrieval Augmented Transformer for Program Repair | 2024 | Maybe | Medium |  |
| REC-0143 | Cross-Modal Retrieval and Retrieval-Augmented Inference for IoT-Enabled Clinical Decision Support | 2026 | Maybe | Medium |  |
| REC-0148 | Agentic RAG for Command Generation in Automated Penetration Testing | 2025 | Maybe | Medium |  |
| REC-0150 | LLM-based Security Audit Assistant for Configuration File Analysis | 2025 | Maybe | Medium |  |
| REC-0152 | Automated C/C++ Program Repair for High-Level Synthesis via Large Language Models | 2024 | Maybe | Medium |  |
| REC-0153 | AutoPentestAL: An automated penetration testing framework with active learning capabilities | 2025 | Maybe | Medium |  |
| REC-0158 | Knowledge-Enhanced Program Repair for Data Science Code | 2025 | Maybe | Medium |  |
| REC-0161 | LLM-Powered Agentic AI Approach to Securing EV Charging Systems Against Cyber Threats | 2025 | Maybe | Medium |  |
| REC-0168 | Automated Proactive Logging Quality Improvement for Large-Scale Codebases | 2025 | Maybe | Medium |  |
| REC-0170 | DeepDesc: integrating retrieval-augmented generation with large language models for smart contract vulnerability detection | 2025 | Maybe | Low | No abstract available; final decision kept conservative. |
| REC-0171 | VDM-IOG, a framework of inference on graph in retrieval-augmented generation for vulnerability description mapping | 2026 | Maybe | Low | No abstract available; final decision kept conservative. |
| REC-0172 | Source Code Vulnerability Detection Method Based on Hybrid Retrieval-Augmented Generation Technology | 2026 | Maybe | Low | No abstract available; final decision kept conservative. |
| REC-0194 | Retrieval-augmented patch generation for geosynchronous satellite status forecasting | 2026 | Maybe | Low | No abstract available; final decision kept conservative. |
| REC-0202 | A Multi-agent RAG Framework for Automated Source Code Vulnerability Detection and Repair | 2026 | Maybe | Low | No abstract available; final decision kept conservative. |
| REC-0204 | ReAPR: Automatic program repair via retrieval-augmented large language models | 2025 | Maybe | Low | No abstract available; final decision kept conservative. |
| REC-0231 | Autosecagent: a semi-automated AI-driven penetration testing framework through recursive memory and real-time RAG | 2026 | Maybe | Low | No abstract available; final decision kept conservative. |
| REC-0232 | KLRAG: Deep Learning Library Vulnerability Detection via Knowledge-Level RAG | 2025 | Maybe | Low | No abstract available; final decision kept conservative. |
| REC-1170 | Fight Poison with Poison: Enhancing Robustness in Few-shot Machine-Generated Text Detection with Adversarial Training | 2026 | Maybe | Medium |  |
| REC-1182 | SecureRAG-RTL: A Retrieval-Augmented, Multi-Agent, Zero-Shot LLM-Driven Framework for Hardware Vulnerability Detection | 2026 | Maybe | Medium |  |
| REC-1183 | ActiShade: Activating Overshadowed Knowledge to Guide Multi-Hop Reasoning in Large Language Models | 2026 | Maybe | Medium |  |
| REC-1187 | Bilevel Optimization for Covert Memory Tampering in Heterogeneous Multi-Agent Architectures (XAMT) | 2025 | Maybe | Medium |  |
| REC-1192 | Adapting Large Language Models to Emerging Cybersecurity using Retrieval Augmented Generation | 2025 | Maybe | Medium |  |
| REC-1199 | CryptoScope: Utilizing Large Language Models for Automated Cryptographic Logic Vulnerability Detection | 2025 | Maybe | Medium |  |
| REC-1202 | AutoRAG-LoRA: Hallucination-Triggered Knowledge Retuning via Lightweight Adapters | 2025 | Maybe | Medium |  |
| REC-1203 | GraphRunner: A Multi-Stage Framework for Efficient and Accurate Graph-Based Retrieval | 2025 | Maybe | Medium |  |
| REC-1205 | SV-LLM: An Agentic Approach for SoC Security Verification using Large Language Models | 2025 | Maybe | Medium |  |
| REC-1206 | LLM Embedding-based Attribution (LEA): Quantifying Source Contributions to Generative Model's Response for Vulnerability Analysis | 2025 | Maybe | Medium |  |
| REC-1207 | Through the Stealth Lens: Rethinking Attacks and Defenses in RAG | 2025 | Maybe | Medium |  |
| REC-1209 | Ranking Free RAG : Replacing Re-ranking with Selection in RAG for Sensitive Domains | 2026 | Maybe | Medium |  |
| REC-1213 | LLMpatronous: Harnessing the Power of LLMs For Vulnerability Detection | 2025 | Maybe | Medium |  |
| REC-1217 | LLM-Assisted Proactive Threat Intelligence for Automated Reasoning | 2025 | Maybe | Medium |  |
| REC-1218 | LettuceDetect: A Hallucination Detection Framework for RAG Applications | 2025 | Maybe | Medium |  |
| REC-1219 | Towards Context-Robust LLMs: A Gated Representation Fine-tuning Approach | 2025 | Maybe | Medium |  |
| REC-1220 | Trustful LLMs: Customizing and Grounding Text Generation with Knowledge Bases and Dual Decoders | 2024 | Maybe | Medium |  |
| REC-1221 | LProtector: An LLM-driven Vulnerability Detection System | 2024 | Maybe | Medium |  |
| REC-1226 | Vul- RAG : Enhancing LLM-based Vulnerability Detection via Knowledge-level RAG | 2025 | Maybe | Medium |  |
| REC-1228 | FACTOID: FACtual enTailment fOr hallucInation Detection | 2024 | Maybe | Medium |  |
| REC-1230 | Retrieval - Augmented Text Generation: Methods, Challenges, and Applications | 2025 | Maybe | Low | Google Scholar snippet only; not treated as full abstract evidence. |

## 未完成或不确定事项

- ACM Digital Library URL 返回 403 Forbidden，未抽取记录。
- Google Scholar 仅处理提供 URL 的第一页可见结果；未继续抓取第 2 页及以后结果。
- Springer Nature CSV 不含摘要，未批量访问每篇 Springer 页面补摘要。
- 这是 title/abstract/snippet 层面的自动初筛，Final Include/Maybe 仍需要人工全文复核。
