# llm-eval

LLM evaluation library in C++. Run prompts N times, measure consistency and variance, compare models. One header.

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue)
![License: MIT](https://img.shields.io/badge/License-MIT-green)
![Single Header](https://img.shields.io/badge/library-single--header-orange)

---

## 30-second quickstart

```cpp
#define LLM_EVAL_IMPLEMENTATION
#include "llm_eval.hpp"
#include <cstdlib>
#include <iostream>

int main() {
    llm::EvalConfig cfg;
    cfg.api_key = std::getenv("OPENAI_API_KEY");
    cfg.model   = "gpt-4o-mini";
    cfg.runs    = 10;

    auto result = llm::evaluate("What is the capital of France?", cfg);

    std::cout << result.summary << "\n";
    // gpt-4o-mini: 10 runs, 100% success, avg 5 chars, similarity 98%, avg latency 320ms.
}
```

---

## Installation

```bash
cp include/llm_eval.hpp your-project/
```

Link with `-lcurl`.

---

## API Reference

```cpp
// Evaluate a single prompt N times
llm::EvalResult r = llm::evaluate(prompt, config);

// Metrics
r.metrics.success_rate;    // 0.0-1.0
r.metrics.avg_similarity;  // word-level Jaccard across runs
r.metrics.length_cv;       // coefficient of variation (stddev/mean)
r.metrics.p95_latency_ms;
r.metrics.high_variance;   // flag: CV > 0.3
r.metrics.inconsistent;    // flag: avg similarity < 0.5
r.metrics.unreliable;      // flag: success_rate < 0.9

// Compare two models
auto cmp = llm::compare(prompt, config_a, config_b);
std::cout << cmp.winner << "\n"; // "a", "b", or "tie"

// Compare two system prompts
auto cmp = llm::compare_prompts(prompt, system_a, system_b, base_config);

// Score a response against expected keywords
auto sc = llm::score_response(response, {"Paris", "capital", "France"});
std::cout << sc.score << "\n"; // 0.0-1.0
```

---

## Building

```bash
cmake -B build && cmake --build build
export OPENAI_API_KEY=sk-...
./build/basic_eval
```

---

## See Also

| Repo | What it does |
|------|-------------|
| [llm-stream](https://github.com/Mattbusel/llm-stream) | Stream OpenAI & Anthropic responses token by token |
| [llm-cache](https://github.com/Mattbusel/llm-cache) | Cache responses, skip redundant calls |
| [llm-cost](https://github.com/Mattbusel/llm-cost) | Token counting + cost estimation |
| [llm-retry](https://github.com/Mattbusel/llm-retry) | Retry with backoff + circuit breaker |
| [llm-format](https://github.com/Mattbusel/llm-format) | Structured output enforcement |
| [llm-embed](https://github.com/Mattbusel/llm-embed) | Text embeddings + nearest-neighbor search |
| [llm-pool](https://github.com/Mattbusel/llm-pool) | Concurrent request pool + rate limiting |
| [llm-log](https://github.com/Mattbusel/llm-log) | Structured JSONL logger for LLM calls |
| [llm-template](https://github.com/Mattbusel/llm-template) | Prompt templating with loops + conditionals |
| [llm-agent](https://github.com/Mattbusel/llm-agent) | Tool-calling agent loop |
| [llm-rag](https://github.com/Mattbusel/llm-rag) | Full RAG pipeline |
| [llm-eval](https://github.com/Mattbusel/llm-eval) | Consistency and quality evaluation |

---

## License

MIT — see [LICENSE](LICENSE).
