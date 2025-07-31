#include "say.h"
#include <string_view>
#include <stdexcept>
#include <array>

namespace say {
std::string ones_in_english(ssize_t number) {
    if(number < 0 || number > 9)
        throw std::domain_error("Wrond ones");
    static std::array<std::string_view, 10> ones{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; //TODO: replace with switch
    return std::string{ones[number]};
}

std::string tens_in_engtlish(ssize_t number) {
    if(number < 10 || number > 19)
        throw std::domain_error("Wrong tens");
    static std::array<std::string_view, 10> tens{"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"}; //TODO: replace with switch 
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
        static std::array<std::string_view, 8> tens_from_twenty{"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}; //TODO: replace with switch
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

std::string number_class_in_english(ssize_t number_class) {
    if(number_class < 0 || number_class > 3)
        throw std::domain_error("Wrong number class");
    static std::array<std::string_view, 4> classes{"", " thousand", " million", " billion"}; //TODO: replace with switch
    return std::string{classes[number_class]};
}
std::string in_english(ssize_t number) {
    if(number < 0 || number > 999'999'999'999)
        throw std::domain_error("You are wrong!");

    if(number == 0)
        return ones_in_english(number);

    std::string in_english_{};
    auto number_class{0};
    std::string temp{};
    while(number) {
        if(!in_english_.empty() && number % 1000)
            in_english_.insert(0, " ");
        if(number % 1000) {
            temp += up_to_thousand_in_english(number % 1000);
            temp += number_class_in_english(number_class);
            
            in_english_.insert(0, temp);
            temp.clear();
        }
        ++number_class;
        number /= 1000;
    }
    return in_english_;   
}
}  // namespace say
