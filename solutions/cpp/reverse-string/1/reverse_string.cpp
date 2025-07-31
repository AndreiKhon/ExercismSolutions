#include "reverse_string.h"

#include <algorithm>

namespace reverse_string {
    std::string reverse_string(const std::string& str_to_reverse) {
        std::string reversed_string(str_to_reverse);
        std::reverse(reversed_string.begin(), reversed_string.end());
        return reversed_string;
    }
}  // namespace reverse_string
