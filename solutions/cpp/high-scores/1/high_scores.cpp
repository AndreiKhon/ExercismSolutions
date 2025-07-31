#include "high_scores.h"
#include <algorithm>

namespace arcade {

    std::vector<int> HighScores::list_scores() {
        return scores;
    }

    int HighScores::latest_score() {
        if(scores.empty())
            return {};
        return scores.back();
    }

    int HighScores::personal_best() {
        auto it = std::max_element(std::begin(scores), std::end(scores));
        if(it != std::end(scores))
            return *it;
        return {};
    }

    std::vector<int> HighScores::top_three() {
        auto scores_copy{scores};
        std::sort(begin(scores_copy), end(scores_copy), std::greater<int>{});
        scores_copy.resize(std::min(scores_copy.size(), static_cast<size_t>(3)));
        return scores_copy;
    }

}  // namespace arcade
