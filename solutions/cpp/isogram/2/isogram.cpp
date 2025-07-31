#include "isogram.h"
#include <unordered_set>
#include <cstddef>
namespace isogram {
    bool is_isogram(std::string_view word) {
        std::unordered_set<unsigned char> characterSet;
        for(auto ch: word) {
            if(std::isalpha(ch)) {
                auto [insertValue, isInsert] = characterSet.insert(std::tolower(ch));
                if(!isInsert)
                    return false;
            }
        }
        return true;
    }
}  // namespace isogram
