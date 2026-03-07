#define LLM_EVAL_IMPLEMENTATION
#include "llm_eval.hpp"
#include <cstdlib>
#include <iostream>
int main() {
    const char* key = std::getenv("OPENAI_API_KEY");
    if (!key || !key[0]) { std::cerr << "OPENAI_API_KEY not set\n"; return 1; }
    llm::EvalConfig cfg;
    cfg.api_key     = key;
    cfg.model       = "gpt-4o-mini";
    cfg.runs        = 5;
    cfg.temperature = 0.7;
    std::string prompt = "What is the capital of France? Answer in one word.";
    std::cout << "Evaluating: \"" << prompt << "\"\n"
              << "Model: " << cfg.model << ", Runs: " << cfg.runs << "\n\n";
    auto result = llm::evaluate(prompt, cfg);
    std::cout << "=== Individual Runs ===\n";
    for (const auto& r : result.runs)
        std::cout << "  [" << r.run_index << "] "
                  << (r.success ? "" : "FAIL: ")
                  << r.response.substr(0, 60)
                  << " (" << static_cast<int>(r.latency_ms) << "ms)\n";
    const auto& m = result.metrics;
    std::cout << "\n=== Metrics ===\n"
              << "Success rate:    " << static_cast<int>(m.success_rate*100) << "%\n"
              << "Avg length:      " << static_cast<int>(m.avg_length) << " chars\n"
              << "Length CV:       " << m.length_cv << (m.high_variance?" [HIGH VARIANCE]":"")<< "\n"
              << "Avg similarity:  " << m.avg_similarity << (m.inconsistent?" [INCONSISTENT]":"") << "\n"
              << "Avg latency:     " << static_cast<int>(m.avg_latency_ms) << "ms\n"
              << "P95 latency:     " << static_cast<int>(m.p95_latency_ms) << "ms\n"
              << "\nSummary: " << result.summary << "\n";
    // Score against expected keyword
    for (const auto& r : result.runs) {
        auto sc = llm::score_response(r.response, {"Paris", "paris"});
        std::cout << "  Run " << r.run_index << " score: " << sc.score;
        if (sc.found.empty()) std::cout << " [MISSING: Paris]";
        std::cout << "\n";
    }
    return 0;
}
