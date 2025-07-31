#if !defined(LUHN_H)
#define LUHN_H
#include <string_view>
#include <iostream>
#include <numeric>
#include <algorithm>
namespace luhn {
    inline bool valid(std::string_view sin) {
        auto num_count = std::count_if(sin.begin(), sin.end(), static_cast<int(*)(int)>(std::isdigit));
        if(num_count <= 1)
            return false;
        if(sin.find_first_not_of("0123456789 ") != std::string_view::npos)
            return false;
        size_t sum = 0;
        size_t counter = 0;
        for(ssize_t i = sin.length() - 1; i >= 0; --i) {
            if(std::isdigit(sin[i])) {
                auto value = sin[i] - '0';
                if(counter & 1) {
                    auto doubled_value = value + value;
                    if(doubled_value >= 10)
                        doubled_value -= 9;
                    sum += doubled_value;
                }
                else
                    sum += value;
                ++counter;
            }
        }
        return sum % 10 == 0;
    }
}  // namespace luhn

#endif // LUHN_H