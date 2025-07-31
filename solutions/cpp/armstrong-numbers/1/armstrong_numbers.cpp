#include "armstrong_numbers.h"
#include <cmath>
namespace armstrong_numbers {
    [[nodiscard]] constexpr auto num_of_digit(uint64_t num) {
        auto digit_count = 0;
        while(num) {
            ++digit_count;
            num /= 10;
        }
        return digit_count;
    }
    bool is_armstrong_number(uint64_t num) {
        auto digit_count = num_of_digit(num);
        auto num_copy = num;
        uint64_t sum = 0;
        while(num_copy) {
            sum += std::pow(num_copy % 10, digit_count);
            num_copy /= 10;
        }
        return sum == num;
    }
}  // namespace armstrong_numbers
