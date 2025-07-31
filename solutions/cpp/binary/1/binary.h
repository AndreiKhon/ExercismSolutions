#if !defined(BINARY_H)
#define BINARY_H
#include <cstddef>
#include <string_view>
#include <cmath>
namespace binary {
    inline size_t convert(std::string_view binary) {
        if(binary.find_first_not_of("01") != std::string_view::npos)
            return 0;
        size_t counter = 0;
        size_t decimal = 0;
        for(auto it = binary.crbegin(); it != binary.crend(); ++it) {
            auto trin = *it - '0';
            decimal += trin * std::pow(2, counter++);
        }
        return decimal;
    }
}  // namespace binary

#endif // BINARY_H