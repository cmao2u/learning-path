import fs from "node:fs/promises";
import path from "node:path";
import { SpreadsheetFile, Workbook } from "@oai/artifact-tool";

const cwd = process.cwd();
const searchDate = "2026-05-10";

const files = {
  ieeeCsv: "C:\\Users\\cmao2\\Downloads\\export2026.05.10-04.14.29.csv",
  springerCsv: "C:\\Users\\cmao2\\Downloads\\SearchResults (1).csv",
  arxivHtml: path.join(cwd, "web_arxiv.html"),
  googleHtml: path.join(cwd, "web_google.html"),
  workbook: path.join(cwd, "RAG_Vulnerability_Literature_Screening.xlsx"),
  report: path.join(cwd, "Screening_Report.md"),
};

const urls = {
  acm: "https://dl.acm.org/action/doSearch?AllField=%28%22retrieval-augmented+generation%22+OR+%22retrieval+augmented+generation%22++OR+%22RAG%22++OR+%22retrieval-augmented%22+OR+%22retrieval+augmented%22++OR+%22retrieval-enhanced+generation%22+OR+%22retrieval+enhanced+generation%22++OR+%22knowledge-augmented+generation%22+OR+%22knowledge+augmented+generation%22%29+AND+%28vulnerab*++OR+%22software+vulnerability%22+OR+%22code+vulnerability%22++OR+%22vulnerability+detection%22+OR+%22vulnerability+assessment%22++OR+%22vulnerability+analysis%22+OR+%22vulnerability+understanding%22++OR+%22vulnerability+repair%22+OR+%22vulnerability+description%22++OR+%22patch+generation%22+OR+%22program+repair%22++OR+%22vulnerability+patch%22+OR+%22security+patch%22+OR+%22patch+presence%22++OR+%22API+misuse%22++OR+%22security+flaw%22+OR+%22security+bug%22++OR+CVE+OR+CWE++OR+%22smart+contract+vulnerability%22+OR+%22smart+contract+security%22%29",
  arxiv: "https://arxiv.org/search/?query=vulnerability+detection+RAG&searchtype=all&source=header&order=-announced_date_first&size=200&abstracts=show",
  google: "https://scholar.google.com/scholar?q=%28%22retrieval-augmented+generation%22+OR+%22retrieval+augmented+generation%22++OR+%22RAG%22++OR+%22retrieval-augmented%22+OR+%22retrieval+augmented%22++OR+%22retrieval-enhanced+generation%22+OR+%22retrieval+enhanced+generation%22++OR+%22knowledge-augmented+generation%22+OR+%22knowledge+augmented+generation%22%29+AND+%28vulnerab*++OR+%22software+vulnerability%22+OR+%22code+vulnerability%22++OR+%22vulnerability+detection%22+OR+%22vulnerability+assessment%22++OR+%22vulnerability+analysis%22+OR+%22vulnerability+understanding%22++OR+%22vulnerability+repair%22+OR+%22vulnerability+description%22++OR+%22patch+generation%22+OR+%22program+repair%22++OR+%22vulnerability+patch%22+OR+%22security+patch%22+OR+%22patch+presence%22++OR+%22API+misuse%22++OR+%22security+flaw%22+OR+%22security+bug%22++OR+CVE+OR+CWE++OR+%22smart+contract+vulnerability%22+OR+%22smart+contract+security%22%29&hl=zh-CN&as_sdt=0%2C5&as_ylo=2024&as_yhi=2026",
};

const generalSearchString = `(
  "retrieval-augmented generation" OR "retrieval augmented generation"
  OR "RAG"
  OR "retrieval-augmented" OR "retrieval augmented"
  OR "retrieval-enhanced generation" OR "retrieval enhanced generation"
  OR "knowledge-augmented generation" OR "knowledge augmented generation"
)
AND
(
  vulnerab*
  OR "software vulnerability" OR "code vulnerability"
  OR "vulnerability detection" OR "vulnerability assessment"
  OR "vulnerability analysis" OR "vulnerability understanding"
  OR "vulnerability repair" OR "vulnerability description"
  OR "patch generation" OR "program repair"
  OR "vulnerability patch" OR "security patch" OR "patch presence"
  OR "API misuse"
  OR "security flaw" OR "security bug"
  OR CVE OR CWE
  OR "smart contract vulnerability" OR "smart contract security"
)`;

const headers = {
  searchLog: [
    "Database",
    "Search_URL_or_File",
    "Search_String_Used",
    "Search_Date",
    "Raw_Results_Reported",
    "Records_Extracted",
    "Notes",
    "Access_Status",
  ],
  raw: [
    "Raw_ID",
    "Database",
    "Title",
    "Authors",
    "Year",
    "Venue",
    "Publication_Type",
    "DOI",
    "arXiv_ID",
    "URL",
    "Abstract",
    "Keywords",
    "Source_File_or_URL",
    "Extraction_Notes",
  ],
  dedup: [
    "Record_ID",
    "Title",
    "Authors",
    "Year",
    "Venue",
    "Publication_Type",
    "DOI",
    "arXiv_ID",
    "URL",
    "Abstract",
    "Databases_Found_In",
    "Duplicate_Status",
    "Duplicate_Of",
    "Deduplication_Reason",
  ],
  screening: [
    "Record_ID",
    "Title",
    "Authors",
    "Year",
    "Venue",
    "DOI_or_arXiv_ID",
    "URL",
    "RAG_Related",
    "Vulnerability_Related",
    "Software_Code_Related",
    "Primary_Study",
    "Task_Category",
    "Title_Decision",
    "Abstract_Decision",
    "Final_Initial_Decision",
    "Exclusion_Reason",
    "Confidence",
    "Notes",
  ],
};

function csvParse(text) {
  text = text.replace(/^\uFEFF/, "");
  const rows = [];
  let row = [];
  let field = "";
  let inQuotes = false;
  for (let i = 0; i < text.length; i += 1) {
    const ch = text[i];
    const next = text[i + 1];
    if (inQuotes) {
      if (ch === '"' && next === '"') {
        field += '"';
        i += 1;
      } else if (ch === '"') {
        inQuotes = false;
      } else {
        field += ch;
      }
      continue;
    }
    if (ch === '"') {
      inQuotes = true;
    } else if (ch === ",") {
      row.push(field);
      field = "";
    } else if (ch === "\r") {
      if (next === "\n") i += 1;
      row.push(field);
      rows.push(row);
      row = [];
      field = "";
    } else if (ch === "\n") {
      row.push(field);
      rows.push(row);
      row = [];
      field = "";
    } else {
      field += ch;
    }
  }
  row.push(field);
  if (row.length > 1 || row[0] !== "") rows.push(row);
  if (!rows.length) return [];
  const rawHeaders = rows[0].map((h) => h.trim());
  return rows.slice(1).map((r) => {
    const obj = {};
    rawHeaders.forEach((h, idx) => {
      obj[h] = (r[idx] ?? "").trim();
    });
    return obj;
  });
}

function decodeHtml(value) {
  if (!value) return "";
  return value
    .replace(/<br\s*\/?>/gi, " ")
    .replace(/&nbsp;/gi, " ")
    .replace(/&amp;/gi, "&")
    .replace(/&lt;/gi, "<")
    .replace(/&gt;/gi, ">")
    .replace(/&quot;/gi, '"')
    .replace(/&#39;/g, "'")
    .replace(/&apos;/gi, "'")
    .replace(/&ndash;/gi, "-")
    .replace(/&mdash;/gi, "-")
    .replace(/&hellip;/gi, "...")
    .replace(/&#x([0-9a-f]+);/gi, (_, hex) => String.fromCodePoint(parseInt(hex, 16)))
    .replace(/&#(\d+);/g, (_, dec) => String.fromCodePoint(parseInt(dec, 10)));
}

function stripTags(value) {
  return decodeHtml(String(value ?? ""))
    .replace(/<script[\s\S]*?<\/script>/gi, " ")
    .replace(/<style[\s\S]*?<\/style>/gi, " ")
    .replace(/<[^>]+>/g, " ")
    .replace(/\s+/g, " ")
    .trim();
}

function cleanText(value) {
  return String(value ?? "")
    .replace(/\s+/g, " ")
    .trim();
}

function normalizeDoi(doi) {
  return cleanText(doi)
    .replace(/^https?:\/\/(dx\.)?doi\.org\//i, "")
    .replace(/^doi:\s*/i, "")
    .trim()
    .toLowerCase();
}

function normalizeArxiv(id) {
  return cleanText(id)
    .replace(/^arxiv:/i, "")
    .replace(/v\d+$/i, "")
    .toLowerCase();
}

function normalizeTitle(title) {
  return cleanText(title)
    .replace(/^\s*(poster|demo|short paper|research paper)\s*:\s*/i, "")
    .toLowerCase()
    .replace(/['’]/g, "")
    .replace(/[^a-z0-9]+/g, " ")
    .replace(/\s+/g, " ")
    .trim();
}

function firstAuthor(authors) {
  const clean = cleanText(authors).replace(/\bet al\.?$/i, "");
  const parts = clean.split(/\s*;\s*|\s*,\s+|\s+and\s+/i).filter(Boolean);
  return normalizeTitle(parts[0] ?? "");
}

function extractYear(text) {
  const match = String(text ?? "").match(/\b(20\d{2}|19\d{2})\b/);
  return match ? match[1] : "";
}

function extractArxivFromUrl(url) {
  const match = String(url ?? "").match(/arxiv\.org\/(?:abs|pdf)\/([0-9]{4}\.[0-9]{4,5})(?:v\d+)?/i);
  return match ? normalizeArxiv(match[1]) : "";
}

function extractDoiFromUrl(url) {
  const raw = String(url ?? "");
  const doiOrg = raw.match(/doi\.org\/(10\.[^?#\s]+)/i);
  if (doiOrg) return normalizeDoi(decodeURIComponent(doiOrg[1]));
  const springer = raw.match(/(?:article|chapter)\/(10\.[^?#\s]+)/i);
  if (springer) return normalizeDoi(decodeURIComponent(springer[1]));
  return "";
}

function makeRawId(database, idx) {
  const prefix = {
    "IEEE Xplore": "IEEE",
    "Springer Nature": "SPR",
    arXiv: "ARXIV",
    "Google Scholar": "GS",
  }[database] ?? "RAW";
  return `${prefix}-${String(idx + 1).padStart(4, "0")}`;
}

function parseIeee(rows) {
  return rows.map((r, idx) => ({
    Raw_ID: makeRawId("IEEE Xplore", idx),
    Database: "IEEE Xplore",
    Title: cleanText(r["Document Title"]),
    Authors: cleanText(r.Authors),
    Year: cleanText(r["Publication Year"]),
    Venue: cleanText(r["Publication Title"]),
    Publication_Type: cleanText(r["Document Identifier"]),
    DOI: normalizeDoi(r.DOI),
    arXiv_ID: "",
    URL: cleanText(r["PDF Link"]) || (r.DOI ? `https://doi.org/${normalizeDoi(r.DOI)}` : ""),
    Abstract: cleanText(r.Abstract),
    Keywords: [r["Author Keywords"], r["IEEE Terms"], r.Mesh_Terms].filter(Boolean).map(cleanText).join("; "),
    Source_File_or_URL: files.ieeeCsv,
    Extraction_Notes: "Read from IEEE Xplore CSV export.",
  }));
}

function parseSpringer(rows) {
  return rows.map((r, idx) => ({
    Raw_ID: makeRawId("Springer Nature", idx),
    Database: "Springer Nature",
    Title: cleanText(r["Item Title"]),
    Authors: cleanText(r.Authors),
    Year: cleanText(r["Publication Year"]),
    Venue: cleanText(r["Publication Title"] || r["Book Series Title"]),
    Publication_Type: cleanText(r["Content Type"]),
    DOI: normalizeDoi(r["Item DOI"]),
    arXiv_ID: "",
    URL: cleanText(r.URL),
    Abstract: "",
    Keywords: "",
    Source_File_or_URL: files.springerCsv,
    Extraction_Notes: "Read from Springer Nature CSV export. Export did not include abstracts.",
  }));
}

async function parseArxiv() {
  let html = "";
  try {
    html = await fs.readFile(files.arxivHtml, "utf8");
  } catch {
    return { records: [], totalReported: "TODO", notes: "Saved arXiv HTML file not found." };
  }
  const totalMatch = html.match(/Showing\s+[\s\S]*?of\s+(\d+)\s+results/i);
  const totalReported = totalMatch ? totalMatch[1] : "TODO";
  const blocks = [...html.matchAll(/<li class="arxiv-result">([\s\S]*?)<\/li>/g)].map((m) => m[1]);
  const records = blocks.map((block, idx) => {
    const absUrl = (block.match(/href="(https:\/\/arxiv\.org\/abs\/[^"]+)"/i) ?? [])[1] ?? "";
    const arxivId = extractArxivFromUrl(absUrl);
    const title = stripTags((block.match(/<p class="title is-5 mathjax">([\s\S]*?)<\/p>/i) ?? [])[1] ?? "");
    const authorsBlock = (block.match(/<p class="authors">([\s\S]*?)<\/p>/i) ?? [])[1] ?? "";
    const authors = stripTags(authorsBlock).replace(/^Authors:\s*/i, "");
    const absFull = (block.match(/<span class="abstract-full[^"]*"[^>]*>([\s\S]*?)<a class="is-size-7"[\s\S]*?Less<\/a>/i) ?? [])[1]
      ?? (block.match(/<p class="abstract mathjax">([\s\S]*?)<\/p>/i) ?? [])[1]
      ?? "";
    const abstract = stripTags(absFull).replace(/^Abstract\s*:\s*/i, "");
    const tags = [...block.matchAll(/<span class="tag[^>]*>([\s\S]*?)<\/span>/gi)]
      .map((m) => stripTags(m[1]))
      .filter(Boolean)
      .join("; ");
    const submitted = stripTags((block.match(/<p class="is-size-7">([\s\S]*?)<\/p>/i) ?? [])[1] ?? "");
    return {
      Raw_ID: makeRawId("arXiv", idx),
      Database: "arXiv",
      Title: title,
      Authors: authors,
      Year: extractYear(submitted) || (arxivId ? `20${arxivId.slice(0, 2)}` : ""),
      Venue: "arXiv",
      Publication_Type: "Preprint",
      DOI: "",
      arXiv_ID: arxivId,
      URL: absUrl,
      Abstract: abstract,
      Keywords: tags,
      Source_File_or_URL: urls.arxiv,
      Extraction_Notes: `Read from saved arXiv search result HTML. ${submitted}`,
    };
  });
  return { records, totalReported, notes: `Saved HTML contained ${records.length} visible arXiv result blocks.` };
}

async function parseGoogleScholar() {
  let html = "";
  try {
    html = await fs.readFile(files.googleHtml, "utf8");
  } catch {
    return { records: [], totalReported: "TODO", notes: "Saved Google Scholar HTML file not found." };
  }
  const unusual = /unusual traffic|captcha|not a robot/i.test(html);
  const blocks = [...html.matchAll(/<div class="gs_r gs_or gs_scl"[\s\S]*?(?=<div class="gs_r gs_or gs_scl"|<div id="gs_res_ccl_bot"|<div id="gs_nm")/g)]
    .map((m) => m[0])
    .filter((block) => /<h3 class="gs_rt"/i.test(block));
  const records = blocks.map((block, idx) => {
    const h3 = (block.match(/<h3 class="gs_rt"[^>]*>([\s\S]*?)<\/h3>/i) ?? [])[1] ?? "";
    const aMatch = h3.match(/<a[^>]*href="([^"]+)"[^>]*>([\s\S]*?)<\/a>/i);
    const url = aMatch ? decodeHtml(aMatch[1]) : "";
    const title = stripTags(aMatch ? aMatch[2] : h3).replace(/^\[[^\]]+\]\s*/, "");
    const meta = stripTags((block.match(/<div class="gs_a">([\s\S]*?)<\/div>/i) ?? [])[1] ?? "");
    const snippet = stripTags((block.match(/<div class="gs_rs">([\s\S]*?)<\/div>/i) ?? [])[1] ?? "");
    const year = extractYear(meta);
    const arxivId = extractArxivFromUrl(url) || (meta.match(/arXiv:([0-9]{4}\.[0-9]{4,5})/i)?.[1] ?? "");
    const doi = extractDoiFromUrl(url);
    const authors = meta.split(/\s+-\s+/)[0] ?? meta;
    const venue = meta.split(/\s+-\s+/)[1] ?? "";
    return {
      Raw_ID: makeRawId("Google Scholar", idx),
      Database: "Google Scholar",
      Title: title,
      Authors: cleanText(authors),
      Year: year,
      Venue: cleanText(venue),
      Publication_Type: "Google Scholar result",
      DOI: doi,
      arXiv_ID: normalizeArxiv(arxivId),
      URL: url,
      Abstract: snippet,
      Keywords: "",
      Source_File_or_URL: urls.google,
      Extraction_Notes: "Extracted from visible Google Scholar first page only; Abstract field contains Scholar snippet, not full abstract.",
    };
  });
  return {
    records,
    totalReported: unusual ? "Blocked/CAPTCHA" : "First page only; full hit count not reliably extracted",
    notes: unusual
      ? "Google Scholar page appeared to be blocked by anti-automation."
      : `Saved HTML contained ${records.length} visible Scholar result blocks. Pagination links were visible, but only the provided first page was processed.`,
  };
}

function titleHasRag(text) {
  const t = text.toLowerCase();
  return /retrieval[-\s]?augmented|retrieval[-\s]?enhanced|knowledge[-\s]?augmented|rag[-\s]?based|\brag\b/.test(t);
}

function hasRag(text) {
  const t = text.toLowerCase();
  if (/retrieval[-\s]?augmented generation|retrieval[-\s]?augmented|retrieval[-\s]?enhanced generation|knowledge[-\s]?augmented generation|retrieval[-\s]?based prompting|rag[-\s]?based/.test(t)) {
    return "Yes";
  }
  if (/\brag\b/.test(t) && /retrieval|augment|large language model|llm|generation|prompt/.test(t)) {
    return "Yes";
  }
  if (/\brag\b/.test(t)) return "Unclear";
  return "No";
}

function ragAnotherMeaning(text) {
  const t = text.toLowerCase();
  return /\bred[-\s]?amber[-\s]?green\b|\bred amber green\b|\broughness average gradient\b/.test(t);
}

function hasVulnerability(text) {
  const t = text.toLowerCase();
  if (/vulnerab|cve\b|cwe\b|common vulnerabilities|national vulnerability database|\bnvd\b|weakness enumeration|api misuse|security flaw|security bug|security patch|vulnerability patch|patch presence|smart contract security|smart contract vulnerab|software security|code security|secure code/.test(t)) {
    return "Yes";
  }
  if (/(patch generation|program repair|automated repair|bug repair|penetration testing|security audit|security analysis|threat modeling|attack detection|malware detection|prompt injection|data poisoning|knowledge poisoning|\bsecurity\b|patch|repair|defect|bug\b)/.test(t)) return "Unclear";
  return "No";
}

function hasSoftwareCode(text, title = "") {
  const t = text.toLowerCase();
  const ti = title.toLowerCase();
  if (/software vulnerab|source code|code vulnerab|vulnerable code|code security|secure code|program repair|api misuse|smart contract|solidity|security patch|vulnerability patch|patch presence|inter[-\s]?procedural|data flow graph|call graph|static analysis|github pull request|git repositories|java vulnerab|python package vulnerab|npm package vulnerab|library vulnerab|dependency vulnerab|binary (program|vulnerab)|firmware vulnerab/.test(t)) {
    return "Yes";
  }
  if (/\bcode\b/.test(ti) && /vulnerab|security|patch|repair|quality/.test(ti)) return "Yes";
  const genericNonSoftware = /rag system|retrieval[-\s]?augmented generation systems?|knowledge base poisoning|knowledge poisoning|prompt injection|jailbreak|membership inference|privacy|medical|healthcare|crop|agricultur|finance|tourism|education|legal|transportation|power grid|wireless|sensor|disaster|earthquake|seismic|federated split learning|semantic caching|recommender systems?|malware detection|android malware|honeypot|cyber defense|security operations|cognitive soc|post[-\s]?quantum|cryptograph(y|ic) intelligence|malicious documents|rag extraction attack|graph retrieval[-\s]?augmented generation|graph rag|attack surface/.test(t);
  if (genericNonSoftware) return "No";
  const cveStrong = /\b(cve|cwe)\b|common vulnerabilities|national vulnerability database|\bnvd\b/.test(t)
    && /(mapping|description|assessment|analysis|database|vulnerability report|weakness|exposure|software|code)/.test(t)
    && /vulnerab|\bcve\b|\bcwe\b|\bnvd\b|weakness|exposure|software|code|smart contract|patch|api/.test(ti)
    && !/(malware|honeypot|security operations|cognitive soc|cyber defense|threat intelligence|post[-\s]?quantum|cryptograph(y|ic) intelligence|tourism|healthcare|medical|forestry|transportation|power grid)/.test(t);
  if (cveStrong) return "Yes";
  if (/web vulnerab|penetration testing|security audit|security analysis|cybersecurity|cyber threat|threat intelligence|threat modeling|attack graph|mitre|att&ck|network|cloud|iot|malware|android malware|container misconfiguration|infrastructure[-\s]?as[-\s]?code|configuration file/.test(t)) return "Unclear";
  if (/vulnerab|security|patch|repair|bug/.test(t)) return "Unclear";
  return "No";
}

function primaryStudy(text, pubType = "") {
  const t = `${text} ${pubType}`.toLowerCase();
  if (/survey|systematic literature review|literature review|review of|comprehensive review|mapping study|position paper|vision paper|tutorial/.test(t)) return "No";
  if (/empirical|experiment|benchmark|method|framework|system|approach|model|tool|dataset|evaluation|detect|repair|generate|mapping|analysis|assessment|case study|poster/.test(t)) return "Yes";
  return "Unclear";
}

function taskCategory(text, softwareRelated) {
  const t = text.toLowerCase();
  if (softwareRelated === "No") return "Not Applicable";
  if (/smart contract/.test(t)) return "Smart Contract Security";
  if (/api misuse/.test(t)) return "API Misuse";
  if (/patch presence/.test(t)) return "Patch Presence Test";
  if (/patch generation/.test(t)) return "Patch Generation";
  if (/vulnerability repair|program repair|automated repair|bug repair/.test(t)) return "Vulnerability Repair";
  if (/cve\b|cwe\b|common vulnerabilities|weakness enumeration|vulnerability description/.test(t)) return "CVE/CWE";
  if (/assessment|severity|prioriti[sz]ation|risk/.test(t)) return "Vulnerability Assessment";
  if (/understanding|explanation|description|mapping/.test(t)) return "Vulnerability Understanding";
  if (/analysis|analy[sz]e/.test(t)) return "Vulnerability Analysis";
  if (/detect|detection|classif|locali[sz]ation/.test(t)) return "Vulnerability Detection";
  if (/vulnerab|security|patch|repair/.test(t)) return "Other";
  return "Unclear";
}

function decisionFromFlags({ rag, vuln, software, primary, hasAbstract, sourceIsSnippet }) {
  if (rag === "No") return { decision: "Exclude", reason: "Not RAG" };
  if (rag === "Another") return { decision: "Exclude", reason: "RAG has another meaning" };
  if (vuln === "No") return { decision: "Exclude", reason: "Not vulnerability-related" };
  if (software === "No") return { decision: "Exclude", reason: "Not software/code-related" };
  if (primary === "No") return { decision: "Exclude", reason: "Survey only" };
  if (rag === "Yes" && vuln === "Yes" && software === "Yes" && primary === "Yes") {
    if (!hasAbstract || sourceIsSnippet) return { decision: "Maybe", reason: "" };
    return { decision: "Include", reason: "" };
  }
  return { decision: "Maybe", reason: "" };
}

function titleDecision(title) {
  const rag = ragAnotherMeaning(title) ? "Another" : hasRag(title);
  const vuln = hasVulnerability(title);
  const software = hasSoftwareCode(title, title);
  const primary = primaryStudy(title);
  return decisionFromFlags({ rag, vuln, software, primary, hasAbstract: true, sourceIsSnippet: false }).decision;
}

function screenRecord(record) {
  const title = record.Title ?? "";
  const abstract = record.Abstract ?? "";
  const text = `${title} ${abstract}`;
  const titleOnly = title;
  const another = ragAnotherMeaning(text);
  const rag = another ? "No" : hasRag(text);
  const vuln = hasVulnerability(text);
  const software = hasSoftwareCode(text, title);
  const primary = primaryStudy(text, record.Publication_Type);
  const cat = taskCategory(text, software);
  const sourceIsSnippet = /Google Scholar/.test(record.Databases_Found_In ?? record.Database ?? "") && !/arXiv|IEEE Xplore|Springer Nature|ACM/.test((record.Databases_Found_In ?? "").replace("Google Scholar", ""));
  const titleDec = titleDecision(titleOnly);
  const absDecObj = decisionFromFlags({
    rag: another ? "Another" : rag,
    vuln,
    software,
    primary,
    hasAbstract: Boolean(cleanText(abstract)),
    sourceIsSnippet,
  });
  let finalObj = absDecObj;
  const notes = [];
  if (!cleanText(abstract)) notes.push("No abstract available; final decision kept conservative.");
  if (sourceIsSnippet) notes.push("Google Scholar snippet only; not treated as full abstract evidence.");
  if (another) finalObj = { decision: "Exclude", reason: "RAG has another meaning" };
  if (record.Duplicate_Status === "Duplicate") finalObj = { decision: "Exclude", reason: "Duplicate" };
  const confidence =
    finalObj.decision === "Include" ? "High"
    : finalObj.decision === "Exclude" && cleanText(abstract) ? "High"
    : finalObj.decision === "Exclude" ? "Medium"
    : cleanText(abstract) && !sourceIsSnippet ? "Medium"
    : "Low";
  return {
    Record_ID: record.Record_ID,
    Title: record.Title,
    Authors: record.Authors,
    Year: record.Year,
    Venue: record.Venue,
    DOI_or_arXiv_ID: record.DOI || record.arXiv_ID,
    URL: record.URL,
    RAG_Related: another ? "No" : rag,
    Vulnerability_Related: vuln,
    Software_Code_Related: software,
    Primary_Study: primary,
    Task_Category: cat,
    Title_Decision: titleDec,
    Abstract_Decision: absDecObj.decision,
    Final_Initial_Decision: finalObj.decision,
    Exclusion_Reason: finalObj.decision === "Exclude" ? finalObj.reason || "Other" : "",
    Confidence: confidence,
    Notes: notes.join(" "),
  };
}

function recordQualityScore(r) {
  let score = 0;
  if (r.DOI) score += 20;
  if (r.arXiv_ID) score += 10;
  if (r.Abstract) score += 8;
  if (r.URL) score += 2;
  if (r.Database === "IEEE Xplore") score += 7;
  if (r.Database === "Springer Nature") score += 6;
  if (r.Database === "ACM Digital Library") score += 6;
  if (r.Database === "arXiv") score += 3;
  if (r.Database === "Google Scholar") score -= 2;
  return score;
}

function deduplicate(rawRecords) {
  const parent = rawRecords.map((_, idx) => idx);
  const reasons = new Map();
  const find = (idx) => {
    while (parent[idx] !== idx) {
      parent[idx] = parent[parent[idx]];
      idx = parent[idx];
    }
    return idx;
  };
  const union = (a, b, reason) => {
    const ra = find(a);
    const rb = find(b);
    if (ra === rb) {
      const key = Math.min(ra, rb);
      if (!reasons.has(key)) reasons.set(key, new Set());
      reasons.get(key).add(reason);
      return;
    }
    const keep = Math.min(ra, rb);
    const move = Math.max(ra, rb);
    parent[move] = keep;
    const merged = new Set([...(reasons.get(ra) ?? []), ...(reasons.get(rb) ?? []), reason]);
    reasons.delete(ra);
    reasons.delete(rb);
    reasons.set(keep, merged);
  };
  const isSubstantiveTitle = (title) => {
    const norm = normalizeTitle(title);
    const tokens = norm.split(" ").filter(Boolean);
    const generic = new Set([
      "introduction",
      "conclusion",
      "large language models",
      "human centered llm",
      "manuscript materials",
      "background",
      "related work",
    ]);
    return norm.length >= 25 && tokens.length >= 5 && !generic.has(norm);
  };
  const indexBy = (items, keyFn, reason) => {
    const buckets = new Map();
    items.forEach((r, idx) => {
      const key = keyFn(r);
      if (!key) return;
      if (!buckets.has(key)) buckets.set(key, []);
      buckets.get(key).push(idx);
    });
    for (const indices of buckets.values()) {
      if (indices.length < 2) continue;
      for (let i = 1; i < indices.length; i += 1) union(indices[0], indices[i], reason);
    }
  };

  indexBy(rawRecords, (r) => normalizeDoi(r.DOI), "Matched by DOI.");
  indexBy(rawRecords, (r) => normalizeArxiv(r.arXiv_ID), "Matched by arXiv ID.");
  indexBy(rawRecords, (r) => isSubstantiveTitle(r.Title) ? normalizeTitle(r.Title) : "", "Matched by substantive normalized title.");
  indexBy(rawRecords, (r) => {
    if (!isSubstantiveTitle(r.Title)) return "";
    return `${normalizeTitle(r.Title)}|${firstAuthor(r.Authors)}|${r.Year}`;
  }, "Matched by title + first author + year.");

  const groups = new Map();
  rawRecords.forEach((r, idx) => {
    const root = find(idx);
    if (!groups.has(root)) groups.set(root, { key: String(root), reason: [...(reasons.get(root) ?? [])].join(" "), records: [] });
    groups.get(root).records.push(r);
  });

  const dedup = [];
  const rawToRecord = new Map();
  let idx = 1;
  for (const group of groups.values()) {
    const sorted = [...group.records].sort((a, b) => recordQualityScore(b) - recordQualityScore(a));
    const primary = sorted[0];
    const id = `REC-${String(idx).padStart(4, "0")}`;
    idx += 1;
    const databases = [...new Set(sorted.map((r) => r.Database))].join("; ");
    const duplicateRawIds = sorted.slice(1).map((r) => r.Raw_ID);
    const abstracts = sorted.map((r) => cleanText(r.Abstract)).filter(Boolean);
    const bestAbstract = cleanText(primary.Abstract) || abstracts.sort((a, b) => b.length - a.length)[0] || "";
    const doi = primary.DOI || sorted.map((r) => r.DOI).find(Boolean) || "";
    const arxiv = primary.arXiv_ID || sorted.map((r) => r.arXiv_ID).find(Boolean) || "";
    const url = primary.URL || sorted.map((r) => r.URL).find(Boolean) || "";
    const dedupReason = duplicateRawIds.length
      ? `${group.reason} Kept ${primary.Raw_ID}; duplicates: ${duplicateRawIds.join(", ")}.`
      : "Unique record.";
    const merged = {
      Record_ID: id,
      Title: primary.Title,
      Authors: primary.Authors,
      Year: primary.Year,
      Venue: primary.Venue,
      Publication_Type: primary.Publication_Type,
      DOI: doi,
      arXiv_ID: arxiv,
      URL: url,
      Abstract: bestAbstract,
      Databases_Found_In: databases,
      Duplicate_Status: duplicateRawIds.length ? "Kept with duplicates" : "Unique",
      Duplicate_Of: "",
      Deduplication_Reason: dedupReason,
    };
    dedup.push(merged);
    sorted.forEach((r) => rawToRecord.set(r.Raw_ID, id));
  }
  return { dedup, rawToRecord, duplicatesRemoved: rawRecords.length - dedup.length };
}

function countBy(rows, field) {
  const out = new Map();
  for (const row of rows) {
    const value = cleanText(row[field]) || "(blank)";
    out.set(value, (out.get(value) ?? 0) + 1);
  }
  return [...out.entries()].sort((a, b) => String(a[0]).localeCompare(String(b[0])));
}

function metricRows(summary) {
  const rows = [
    ["Metric", "Value"],
    ["Total raw records extracted", summary.rawTotal],
    ["Total duplicates removed", summary.duplicatesRemoved],
    ["Total deduplicated records", summary.dedupTotal],
    ["Title Include count", summary.title.Include ?? 0],
    ["Title Maybe count", summary.title.Maybe ?? 0],
    ["Title Exclude count", summary.title.Exclude ?? 0],
    ["Abstract Include count", summary.abstract.Include ?? 0],
    ["Abstract Maybe count", summary.abstract.Maybe ?? 0],
    ["Abstract Exclude count", summary.abstract.Exclude ?? 0],
    ["Final Initial Include count", summary.final.Include ?? 0],
    ["Final Initial Maybe count", summary.final.Maybe ?? 0],
    ["Final Initial Exclude count", summary.final.Exclude ?? 0],
    [],
    ["Count by database", ""],
    ["Database", "Count"],
    ...summary.byDatabase,
    [],
    ["Count by task category", ""],
    ["Task_Category", "Count"],
    ...summary.byTask,
    [],
    ["Count by exclusion reason", ""],
    ["Exclusion_Reason", "Count"],
    ...summary.byExclusion,
  ];
  return rows;
}

function objectCounts(rows, field) {
  const obj = {};
  for (const row of rows) {
    const key = row[field] || "(blank)";
    obj[key] = (obj[key] ?? 0) + 1;
  }
  return obj;
}

function prismaRows(summary) {
  const finalInclude = summary.final.Include ?? 0;
  const maybe = summary.final.Maybe ?? 0;
  const reportsSought = finalInclude + maybe;
  return [
    ["PRISMA_Item", "Value", "Notes"],
    ["Records identified from databases", summary.databaseRecords, "IEEE Xplore + Springer Nature + arXiv visible records. ACM inaccessible."],
    ["Records identified from supplementary sources", summary.supplementaryRecords, "Google Scholar first visible page only."],
    ["Records before deduplication", summary.rawTotal, ""],
    ["Duplicates removed", summary.duplicatesRemoved, ""],
    ["Records after deduplication", summary.dedupTotal, ""],
    ["Records excluded after title/abstract screening", summary.final.Exclude ?? 0, "Initial screening only."],
    ["Reports sought for retrieval", reportsSought, "Initial Include + Maybe; user to decide full-text retrieval."],
    ["Reports not retrieved", "TODO", "Full-text retrieval was not performed in this task."],
    ["Full-text reports assessed", "TODO", "Full-text assessment was not performed in this task."],
    ["Full-text reports excluded", "TODO", "Full-text assessment was not performed in this task."],
    ["Studies included in final analysis", "TODO", "Requires manual full-text review."],
  ];
}

function toRows(objects, header) {
  return [header, ...objects.map((obj) => header.map((h) => obj[h] ?? ""))];
}

function colName(n) {
  let s = "";
  while (n > 0) {
    const r = (n - 1) % 26;
    s = String.fromCharCode(65 + r) + s;
    n = Math.floor((n - 1) / 26);
  }
  return s;
}

function sheetRange(rows) {
  const rowCount = Math.max(rows.length, 1);
  const colCount = Math.max(...rows.map((r) => r.length), 1);
  return `A1:${colName(colCount)}${rowCount}`;
}

async function addSheet(workbook, name, rows) {
  const sheet = workbook.worksheets.add(name);
  const paddedWidth = Math.max(...rows.map((r) => r.length), 1);
  const paddedRows = rows.map((r) => {
    const out = [...r];
    while (out.length < paddedWidth) out.push("");
    return out;
  });
  sheet.getRange(sheetRange(paddedRows)).values = paddedRows;
  try {
    sheet.freezePanes = { rows: 1, columns: 0 };
  } catch {
    // Freeze panes are cosmetic; continue if the runtime API differs.
  }
  try {
    sheet.getRange(`A1:${colName(paddedWidth)}1`).format = { font: { bold: true }, fill: { color: "#D9EAF7" } };
  } catch {
    // Formatting is best effort.
  }
  return sheet;
}

async function buildWorkbook({ searchLog, rawRecords, dedupRecords, screening, summaryRows, prisma }) {
  const workbook = Workbook.create();
  try {
    const first = workbook.worksheets.getActiveWorksheet?.();
    if (first) first.delete?.();
  } catch {
    // Some workbook builds start empty; no action needed.
  }
  await addSheet(workbook, "Search_Log", toRows(searchLog, headers.searchLog));
  await addSheet(workbook, "Raw_Records", toRows(rawRecords, headers.raw));
  await addSheet(workbook, "Deduplicated_Records", toRows(dedupRecords, headers.dedup));
  await addSheet(workbook, "Screening", toRows(screening, headers.screening));
  await addSheet(workbook, "Summary", summaryRows);
  await addSheet(workbook, "PRISMA_Counts", prisma);
  const includeOnly = screening.filter((r) => r.Final_Initial_Decision === "Include");
  await addSheet(workbook, "Include_Records", toRows(includeOnly, headers.screening));
  const output = await SpreadsheetFile.exportXlsx(workbook);
  await output.save(files.workbook);
  return workbook;
}

function buildReport({ searchLog, rawRecords, dedupRecords, screening, summary, maybeRecords, inaccessible }) {
  const include = summary.final.Include ?? 0;
  const maybe = summary.final.Maybe ?? 0;
  const exclude = summary.final.Exclude ?? 0;
  const exclusionRows = summary.byExclusion
    .filter(([reason]) => reason !== "(blank)")
    .map(([reason, count]) => `| ${reason} | ${count} |`)
    .join("\n") || "| None | 0 |";
  const dbRows = searchLog
    .map((r) => `| ${r.Database} | ${r.Records_Extracted} | ${r.Access_Status} |`)
    .join("\n");
  const reviewRows = maybeRecords
    .map((r) => `| ${r.Record_ID} | ${escapeMd(r.Title)} | ${escapeMd(r.Year)} | ${r.Final_Initial_Decision} | ${r.Confidence} | ${escapeMd(r.Notes || r.Exclusion_Reason || "")} |`)
    .join("\n") || "| None |  |  |  |  |  |";
  const inaccessibleRows = inaccessible
    .map((r) => `| ${r.Database} | ${escapeMd(r.Search_URL_or_File)} | ${escapeMd(r.Notes)} |`)
    .join("\n") || "| None |  |  |";

  return `# RAG Vulnerability Literature Screening Report

Generated on ${searchDate}.

## 数据读取概况

| Database | Records extracted | Access status |
| --- | ---: | --- |
${dbRows}

## 无法读取或受限来源

| Database | URL/File | Notes |
| --- | --- | --- |
${inaccessibleRows}

## 去重与初筛结果

- Total raw records extracted: ${rawRecords.length}
- Total duplicates removed: ${summary.duplicatesRemoved}
- Total deduplicated records: ${dedupRecords.length}
- Final Initial Include: ${include}
- Final Initial Maybe: ${maybe}
- Final Initial Exclude: ${exclude}

## 主要排除原因

| Exclusion reason | Count |
| --- | ---: |
${exclusionRows}

## 需要人工复核的论文

以下列出所有 Final Initial Decision 为 Maybe，或 Confidence 为 Low 的记录。Springer Nature 导出不含摘要，因此相关标题通常保守标为 Maybe。

| Record_ID | Title | Year | Decision | Confidence | Notes |
| --- | --- | --- | --- | --- | --- |
${reviewRows}

## 未完成或不确定事项

- ACM Digital Library URL 返回 403 Forbidden，未抽取记录。
- Google Scholar 仅处理提供 URL 的第一页可见结果；未继续抓取第 2 页及以后结果。
- Springer Nature CSV 不含摘要，未批量访问每篇 Springer 页面补摘要。
- 这是 title/abstract/snippet 层面的自动初筛，Final Include/Maybe 仍需要人工全文复核。
`;
}

function escapeMd(value) {
  return cleanText(value).replace(/\|/g, "\\|");
}

async function main() {
  const ieeeRows = csvParse(await fs.readFile(files.ieeeCsv, "utf8"));
  const springerRows = csvParse(await fs.readFile(files.springerCsv, "utf8"));
  const ieeeRecords = parseIeee(ieeeRows);
  const springerRecords = parseSpringer(springerRows);
  const arxiv = await parseArxiv();
  const google = await parseGoogleScholar();

  const rawRecords = [...ieeeRecords, ...springerRecords, ...arxiv.records, ...google.records];
  rawRecords.forEach((r) => {
    r.DOI = normalizeDoi(r.DOI);
    r.arXiv_ID = normalizeArxiv(r.arXiv_ID);
  });

  const searchLog = [
    {
      Database: "IEEE Xplore",
      Search_URL_or_File: files.ieeeCsv,
      Search_String_Used: generalSearchString,
      Search_Date: searchDate,
      Raw_Results_Reported: ieeeRows.length,
      Records_Extracted: ieeeRecords.length,
      Notes: "Read from user-provided CSV export.",
      Access_Status: "File read successfully",
    },
    {
      Database: "Springer Nature",
      Search_URL_or_File: files.springerCsv,
      Search_String_Used: generalSearchString,
      Search_Date: searchDate,
      Raw_Results_Reported: springerRows.length,
      Records_Extracted: springerRecords.length,
      Notes: "Read from user-provided CSV export; abstract metadata was not included.",
      Access_Status: "File read successfully",
    },
    {
      Database: "ACM Digital Library",
      Search_URL_or_File: urls.acm,
      Search_String_Used: generalSearchString,
      Search_Date: searchDate,
      Raw_Results_Reported: "TODO",
      Records_Extracted: 0,
      Notes: "HTTP 403 Forbidden when fetching provided URL; no visible records extracted.",
      Access_Status: "Inaccessible",
    },
    {
      Database: "arXiv",
      Search_URL_or_File: urls.arxiv,
      Search_String_Used: "vulnerability detection RAG",
      Search_Date: searchDate,
      Raw_Results_Reported: arxiv.totalReported,
      Records_Extracted: arxiv.records.length,
      Notes: arxiv.notes,
      Access_Status: arxiv.records.length ? "Fetched saved HTML successfully" : "No records extracted",
    },
    {
      Database: "Google Scholar",
      Search_URL_or_File: urls.google,
      Search_String_Used: generalSearchString + " AND year range 2024-2026",
      Search_Date: searchDate,
      Raw_Results_Reported: google.totalReported,
      Records_Extracted: google.records.length,
      Notes: google.notes,
      Access_Status: google.records.length ? "Fetched first page HTML successfully" : "No records extracted",
    },
  ];

  const { dedup, duplicatesRemoved } = deduplicate(rawRecords);
  const screening = dedup.map(screenRecord);

  const summary = {
    rawTotal: rawRecords.length,
    duplicatesRemoved,
    dedupTotal: dedup.length,
    title: objectCounts(screening, "Title_Decision"),
    abstract: objectCounts(screening, "Abstract_Decision"),
    final: objectCounts(screening, "Final_Initial_Decision"),
    byDatabase: countBy(rawRecords, "Database"),
    byTask: countBy(screening, "Task_Category"),
    byExclusion: countBy(screening, "Exclusion_Reason"),
    databaseRecords: ieeeRecords.length + springerRecords.length + arxiv.records.length,
    supplementaryRecords: google.records.length,
  };

  const summaryRows = metricRows(summary);
  const prisma = prismaRows(summary);
  await buildWorkbook({
    searchLog,
    rawRecords,
    dedupRecords: dedup,
    screening,
    summaryRows,
    prisma,
  });

  const maybeRecords = screening
    .filter((r) => r.Final_Initial_Decision === "Maybe" || r.Confidence === "Low")
    .sort((a, b) => {
      const d = a.Final_Initial_Decision.localeCompare(b.Final_Initial_Decision);
      if (d) return d;
      return a.Record_ID.localeCompare(b.Record_ID);
    });
  const inaccessible = searchLog.filter((r) => !/^File read|^Fetched/.test(r.Access_Status));
  const report = buildReport({ searchLog, rawRecords, dedupRecords: dedup, screening, summary, maybeRecords, inaccessible });
  await fs.writeFile(files.report, report, "utf8");

  if (process.env.DEBUG_SCREENING === "1") {
    for (const dec of ["Include", "Maybe", "Exclude"]) {
      const rows = screening.filter((r) => r.Final_Initial_Decision === dec);
      console.log(`### ${dec} ${rows.length}`);
      rows.slice(0, 120).forEach((r) => {
        console.log([
          r.Record_ID,
          r.Title,
          r.Year,
          r.RAG_Related,
          r.Vulnerability_Related,
          r.Software_Code_Related,
          r.Primary_Study,
          r.Task_Category,
          r.Exclusion_Reason,
          r.Confidence,
        ].join(" | "));
      });
    }
  }

  console.log(JSON.stringify({
    workbook: files.workbook,
    report: files.report,
    raw: rawRecords.length,
    deduplicated: dedup.length,
    duplicatesRemoved,
    final: summary.final,
    title: summary.title,
    abstract: summary.abstract,
    byDatabase: Object.fromEntries(summary.byDatabase),
  }, null, 2));
}

main().catch((err) => {
  console.error(err);
  process.exit(1);
});
