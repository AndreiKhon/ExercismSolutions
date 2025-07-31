#include "pangram.h"
#include <set>
#include <cctype>
namespace pangram {
    constexpr auto alphabet_length = 26;
    bool is_pangram(const std::string& str) {
        std::set<char> alphabet_set;
        for(auto ch: str)
            if(std::isalpha(ch))
                alphabet_set.insert(std::tolower(ch));
        return alphabet_set.size() == alphabet_length;
    }
}  // namespace pangram
