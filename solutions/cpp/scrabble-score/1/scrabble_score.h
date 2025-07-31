#if !defined(SCRABBLE_SCORE_H)
#define SCRABBLE_SCORE_H
#include <unordered_map>
#include <string_view>
#include <cstddef>
#include <cctype>
namespace scrabble_score {
    inline std::unordered_map<std::string_view, size_t> letter_values_map{
        {"aeioulnrst", 1},
        {"dg", 2},
        {"bcmp", 3},
        {"fhvwy", 4},
        {"k", 5},
        {"jx", 8},
        {"qz", 10},
    };
    inline size_t score(std::string_view word) {
        size_t score = 0;
        for(auto letter: word) {
            for(const auto& [letters, value]: letter_values_map) {
                if(letters.find(std::tolower(letter)) != std::string_view::npos)
                    score += value;
            }
        }
        return score;
    }
}  // namespace scrabble_score

#endif // SCRABBLE_SCORE_H