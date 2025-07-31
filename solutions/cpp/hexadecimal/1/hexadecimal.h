#if !defined(HEXADECIMAL_H)
#define HEXADECIMAL_H
#include <cstddef>
#include <string_view>
#include <cmath>
namespace hexadecimal {
    inline size_t convert(std::string_view binary) {
        if(binary.find_first_not_of("0123456789abcdef") != std::string_view::npos)
            return 0;
        size_t counter = 0;
        size_t decimal = 0;
        for(auto it = binary.crbegin(); it != binary.crend(); ++it) {
            auto trin = (*it >= 'a') ? (*it - 'a' + 10) : (*it - '0');
            decimal += trin * std::pow(16, counter++);
        }
        return decimal;
    }
}  // namespace hexadecimal

#endif // HEXADECIMAL_H