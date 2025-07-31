#if !defined(TRINARY_H)
#define TRINARY_H
#include <charconv>
#include <cstddef>
#include <string_view>
#include <cmath>
namespace trinary {
    inline size_t to_decimal(std::string_view trinary) {
        if(trinary.find_first_not_of("012") != std::string_view::npos)
            return 0;
        size_t counter = 0;
        size_t decimal = 0;
        for(auto it = trinary.crbegin(); it != trinary.crend(); ++it) {
            auto trin = *it - '0';
            decimal += trin * std::pow(3, counter++);
        }
        return decimal;
    }
}  // namespace trinary

#endif // TRINARY_H