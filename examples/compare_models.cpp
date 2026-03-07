#define LLM_EVAL_IMPLEMENTATION
#include "llm_eval.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>

int main() {
    const char* key = std::getenv("OPENAI_API_KEY");
    if (!key || !*key) { std::cerr << "Set OPENAI_API_KEY\n"; return 1; }

    std::string prompt = "Explain the trade-offs between microservices and monolithic architecture in 2-3 sentences.";

    llm::EvalConfig cfg_a;
    cfg_a.api_key = key; cfg_a.model = "gpt-4o-mini"; cfg_a.runs = 3; cfg_a.temperature = 0.7;

    llm::EvalConfig cfg_b;
    cfg_b.api_key = key; cfg_b.model = "gpt-4o-mini"; cfg_b.runs = 3; cfg_b.temperature = 0.1;

    std::cout << "Comparing:\n  A: " << cfg_a.model << " (temp=" << cfg_a.temperature << ")\n";
    std::cout << "  B: " << cfg_b.model << " (temp=" << cfg_b.temperature << ")\n\n";
    std::cout << "Prompt: \"" << prompt << "\"\n\n";

    auto cmp = llm::compare(prompt, cfg_a, cfg_b);

    std::cout << std::fixed << std::setprecision(3);
    auto print_metrics = [](const std::string& label, const llm::EvalResult& r) {
        std::cout << label << ":\n";
        std::cout << "  avg_similarity=" << r.metrics.avg_similarity
                  << "  length_cv=" << r.metrics.length_cv
                  << "  avg_lat=" << static_cast<int>(r.metrics.avg_latency_ms) << "ms\n";
        std::cout << "  " << r.summary << "\n\n";
    };

    print_metrics("Model A (high temp)", cmp.model_a);
    print_metrics("Model B (low temp)",  cmp.model_b);

    std::cout << "Winner: " << cmp.winner << "\n";
    std::cout << cmp.comparison_summary << "\n";
    return 0;
}
