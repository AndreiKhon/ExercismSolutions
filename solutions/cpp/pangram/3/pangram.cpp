#include "pangram.h"
#include <bitset>
#include <cctype>
namespace pangram {
    constexpr auto alphabet_length = 26;
    
    bool is_pangram(const std::string_view str) {
        std::bitset<alphabet_length> alphabet;
        for(unsigned char ch: str)
            if(std::isalpha(ch)) {
                auto lower = std::tolower(ch);
                size_t index = lower - 'a';
                alphabet.set(index);
            }
        if(alphabet.all())
            return true;
        return false;
    }
}  // namespace pangram
