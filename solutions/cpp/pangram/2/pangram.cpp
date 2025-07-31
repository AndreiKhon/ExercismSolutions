#include "pangram.h"
#include <cctype>
#include <cstdint>

namespace pangram {
    constexpr auto alphabet_length = 26;

    bool is_pangram(const std::string& str) {
        std::uint_fast32_t alphabet_flags = 0;
        for(const unsigned char ch: str)
            if(std::isalpha(ch)) {
                auto lower = std::tolower(ch);
                auto index = lower - 'a';
                alphabet_flags |= 1 << index;
            }
        
        return alphabet_flags == (1 << alphabet_length) - 1;
    }
}  // namespace pangram
