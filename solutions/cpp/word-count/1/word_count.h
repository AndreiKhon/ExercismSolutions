#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H
#include <map>
#include <string>
#include <string_view>
#include <cctype>

namespace word_count {
    std::map<std::string, int> words(std::string_view str);
}  // namespace word_count

#endif // WORD_COUNT_H