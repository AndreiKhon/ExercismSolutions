#if !defined(PANGRAM_H)
#define PANGRAM_H

#include <string_view>

namespace pangram {
    bool is_pangram(const std::string_view);
}  // namespace pangram

#endif // PANGRAM_H