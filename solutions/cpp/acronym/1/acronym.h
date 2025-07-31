#if !defined(ACRONYM_H)
#define ACRONYM_H
#include <string_view>
#include <string>
#include <cstddef>
#include <cctype>
namespace acronym {
    inline std::string acronym(std::string_view phrase) {
        std::string acronym_;
        bool on_word = false;
        for(size_t i = 0; i < phrase.size(); ++i) {
            auto symbol = phrase[i];
            if(std::ispunct(symbol) || std::isspace(symbol)) {
                on_word = false;
                continue;
            }
            if(std::isalpha(symbol) && !on_word) {
                acronym_ += std::toupper(symbol);
                on_word = true;
            }
        }
        return acronym_;
    }
}  // namespace acronym

#endif // ACRONYM_H