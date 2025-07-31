#include "isogram.h"
#include <unordered_set>
#include <cstddef>
namespace isogram {
    bool is_isogram(std::string_view word) {
        std::unordered_set<unsigned char> characterSet;
        size_t alphaCounter = 0;
        for(auto ch: word) {
            if(std::isalpha(ch)) {
                ++alphaCounter;
                characterSet.insert(std::tolower(ch));
            }
        }
        return characterSet.size() == alphaCounter;
    }
}  // namespace isogram
