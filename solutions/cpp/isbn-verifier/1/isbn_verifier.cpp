#include "isbn_verifier.h"
#include <cctype>
namespace isbn_verifier {
    bool is_valid(std::string_view str) {
        if(str.empty())
            return false;
        
        size_t sum{};
        size_t length{};
        auto check_number = str.back();
        if(check_number == 'X')
            sum += 10;
        else
            if(isdigit(check_number))
                sum += check_number - '0';
            else 
                return false;

        ++length;
        
        size_t multiplier{10};
        for(size_t i{}; i < str.size() - 1; ++i) {
            unsigned char ch = str[i];
            if(ch == '-')
                continue;
            if(isdigit(ch)) {
                size_t value = ch - '0';
                sum += value * multiplier--;
                ++length;
            }
            else
                return false;            
        }
        return length == 10 && sum % 11 == 0;
    }
}  // namespace isbn_verifier