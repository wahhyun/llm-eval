# llm-eval

Evaluation + consistency scoring for LLM outputs. One header, libcurl dep.

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![License MIT](https://img.shields.io/badge/license-MIT-green.svg)
![Single Header](https://img.shields.io/badge/single-header-orange.svg)
![Requires libcurl](https://img.shields.io/badge/deps-libcurl-yellow.svg)

## Quickstart

```cpp
#define LLM_EVAL_IMPLEMENTATION
#include "llm_eval.hpp"

llm::EvalConfig cfg;
cfg.api_key = "sk-...";
cfg.model   = "gpt-4o-mini";
cfg.runs    = 10;

auto result = llm::evaluate("Explain what a mutex is in one sentence.", cfg);
std::cout << result.summary << "\n";
// gpt-4o-mini over 10 runs: success=100%, avg_len=142ch, CV=18%, avg_sim=71%, p95_lat=1230ms.
```

## What It Measures

| Metric | Description |
|--------|-------------|
| `length_cv` | Coefficient of variation of response length. High = inconsistent length. |
| `avg_similarity` | Average pairwise Jaccard similarity. Low = inconsistent content. |
| `p95_latency_ms` | 95th percentile latency across all runs |
| `success_rate` | Fraction of runs that completed without API error |
| `high_variance` | Flag: CV > 0.3 |
| `inconsistent` | Flag: avg_similarity < 0.5 |
| `unreliable` | Flag: success_rate < 0.9 |

## Compare Models

```cpp
auto cr = llm::compare("Explain recursion.", cfg_a, cfg_b);
std::cout << "Winner: " << cr.winner << "\n"; // "a", "b", or "tie"
```

## Compare System Prompts

```cpp
auto cr = llm::compare_prompts(
    "Explain recursion.",
    "Be concise.",
    "Be friendly and use examples.",
    base_cfg
);
```

## Score Against Keywords

```cpp
auto score = llm::score_response(response, {"mutex", "lock", "thread"});
std::cout << score.score << "\n";  // 0.0 - 1.0
```

## Examples

| File | What it shows |
|------|--------------|
| [`examples/basic_eval.cpp`](examples/basic_eval.cpp) | 5-run eval + keyword scoring |
| [`examples/compare_models.cpp`](examples/compare_models.cpp) | Compare temperature=0.7 vs 0.0 |

## Building

```bash
cmake -B build && cmake --build build
export OPENAI_API_KEY=sk-...
./build/basic_eval
./build/compare_models
```

## Requirements

C++17. Requires libcurl.

## See Also

| Repo | Purpose |
|------|---------|
| [llm-stream](https://github.com/Mattbusel/llm-stream) | SSE streaming |
| [llm-cache](https://github.com/Mattbusel/llm-cache) | Response caching |
| [llm-cost](https://github.com/Mattbusel/llm-cost) | Token cost estimation |
| [llm-retry](https://github.com/Mattbusel/llm-retry) | Retry + circuit breaker |
| [llm-format](https://github.com/Mattbusel/llm-format) | Markdown/code formatting |
| [llm-embed](https://github.com/Mattbusel/llm-embed) | Embeddings + cosine similarity |
| [llm-pool](https://github.com/Mattbusel/llm-pool) | Connection pooling |
| [llm-log](https://github.com/Mattbusel/llm-log) | Structured logging |
| [llm-template](https://github.com/Mattbusel/llm-template) | Prompt templates |
| [llm-agent](https://github.com/Mattbusel/llm-agent) | Tool-use agent loop |
| [llm-rag](https://github.com/Mattbusel/llm-rag) | Retrieval-augmented generation |
| [llm-eval](https://github.com/Mattbusel/llm-eval) | Output evaluation |
| [llm-chat](https://github.com/Mattbusel/llm-chat) | Multi-turn chat |
| [llm-vision](https://github.com/Mattbusel/llm-vision) | Vision/image inputs |
| [llm-mock](https://github.com/Mattbusel/llm-mock) | Mock LLM for testing |
| [llm-router](https://github.com/Mattbusel/llm-router) | Model routing |
| [llm-guard](https://github.com/Mattbusel/llm-guard) | Content moderation |
| [llm-compress](https://github.com/Mattbusel/llm-compress) | Prompt compression |
| [llm-batch](https://github.com/Mattbusel/llm-batch) | Batch processing |
| [llm-audio](https://github.com/Mattbusel/llm-audio) | Audio transcription/TTS |
| [llm-finetune](https://github.com/Mattbusel/llm-finetune) | Fine-tuning jobs |
| [llm-rank](https://github.com/Mattbusel/llm-rank) | Passage reranking |
| [llm-parse](https://github.com/Mattbusel/llm-parse) | HTML/markdown parsing |
| [llm-trace](https://github.com/Mattbusel/llm-trace) | Distributed tracing |
| [llm-ab](https://github.com/Mattbusel/llm-ab) | A/B testing |
| [llm-json](https://github.com/Mattbusel/llm-json) | JSON parsing/building |

## License

MIT -- see [LICENSE](LICENSE).
