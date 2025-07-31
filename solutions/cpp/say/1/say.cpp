#include "say.h"
#include <string_view>
#include <stdexcept>
#include <array>

namespace say {
std::string ones_in_english(ssize_t number) {
    if(number < 0 || number > 9)
        throw std::domain_error("Wrond ones");
    static std::array<std::string_view, 10> ones{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    return std::string{ones[number]};
}

std::string tens_in_engtlish(ssize_t number) {
    if(number < 10 || number > 19)
        throw std::domain_error("Wrong tens");
    static std::array<std::string_view, 10> tens{"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    return std::string{tens[number % 10]};
}

std::string up_to_hundred_in_english(ssize_t number) {
    if(number < 0 || number > 99)
        throw std::domain_error("Wrong up_to_hundreds");
    auto tens = number / 10 % 10;
    auto ones = number % 10;
    if(tens == 1)
        return tens_in_engtlish(number);
    std::string up_to_hundred_in_english_{};
    if(tens > 1) {
        static std::array<std::string_view, 8> tens_from_twenty{"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        up_to_hundred_in_english_ += tens_from_twenty[tens - 2];
    }
    if(tens && ones)
        up_to_hundred_in_english_ += "-";
    if(ones)
        up_to_hundred_in_english_ += ones_in_english(ones);
    return up_to_hundred_in_english_;
}

std::string up_to_thousand_in_english(ssize_t number) {
    auto hundreds = number / 10 / 10 % 10;
    std::string up_to_thousand_in_english_{};
    if(hundreds) {
        up_to_thousand_in_english_ += ones_in_english(hundreds);
        up_to_thousand_in_english_ += " ";
        up_to_thousand_in_english_ += "hundred";
    }
    if(number / 100 && number % 100)
        up_to_thousand_in_english_ += " ";
    up_to_thousand_in_english_ += up_to_hundred_in_english(number % 100);
    return up_to_thousand_in_english_;    
}

std::string in_english(ssize_t number) {
    if(number < 0 || number > 999'999'999'999)
        throw std::domain_error("You are wrong!");

    if(number == 0)
        return ones_in_english(number);
    
    auto ones = number % 1000;
    auto thousands = number / 1000 % 1000;
    auto millions = number / 1000 / 1000 % 1000;
    auto billions = number / 1000 / 1000 / 1000 % 1000;

    std::string in_english_{};
    if(billions) {
        in_english_ += up_to_thousand_in_english(billions);
        in_english_ += " billion";
    }
    if(millions) {
        if(billions)
            in_english_ += " ";
        in_english_ += up_to_thousand_in_english(millions);
        in_english_ += " million";
    }
    if(thousands) {
        if(billions || millions)
            in_english_ += " ";
        in_english_ += up_to_thousand_in_english(thousands);
        in_english_ += " thousand";
    }
    if(ones) {
        if(billions || millions || thousands)
            in_english_ += " ";
        in_english_ += up_to_thousand_in_english(ones);
    }
    return in_english_;   
}
}  // namespace say
