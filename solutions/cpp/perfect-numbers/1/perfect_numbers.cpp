#include "perfect_numbers.h"
#include <stdexcept>
namespace perfect_numbers {

    perfect_numbers classify(int number) {
        if(number <= 0)
            throw std::domain_error("");
        
        int sum{};
        for(int i{1}; i < number; ++i) {
            if(number % i == 0)
                sum += i;
        }

        if(sum == number)
            return perfect;
        if(sum > number)
            return abundant;
        if(sum < number)
            return deficient;
        return {};
    }
}  // namespace perfect_numbers
