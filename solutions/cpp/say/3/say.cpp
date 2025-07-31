#include "say.h"
#include <string_view>
#include <stdexcept>
#include <array>
#include <cassert>
#include <sstream>
#include <vector>
#include <numeric>

namespace {

std::string up_to_twenty_in_english(std::int64_t number) {
    const static std::array<std::string_view, 20> up_to_twenty{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    return std::string{up_to_twenty[number]};
}

std::string ones_in_english(std::int64_t number) {
    return up_to_twenty_in_english(number);
}

std::string from_twenty_up_to_hundred_in_english(std::int64_t number) {
    const static std::array<std::string_view, 8> tens_from_twenty{"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    
    auto tens = number / 10;
    auto ones = number % 10;

    std::ostringstream from_twenty_up_to_hundred_in_english_sstream{};    
    
    from_twenty_up_to_hundred_in_english_sstream << tens_from_twenty[tens - 2];
    if(tens != 0 && ones != 0)
        from_twenty_up_to_hundred_in_english_sstream << "-";
    if(ones != 0)
        from_twenty_up_to_hundred_in_english_sstream << ones_in_english(ones);
    return from_twenty_up_to_hundred_in_english_sstream.str();
}

std::string up_to_hundred_in_english(std::int64_t number) {
    if(number == 0)
        return {};
    if(number < 20)
        return up_to_twenty_in_english(number);
    return from_twenty_up_to_hundred_in_english(number);
}

std::string up_to_thousand_in_english(std::int64_t number) {
    auto hundreds = number / 10 / 10 % 10;
    std::ostringstream up_to_thousand_in_english_sstream{};
    
    if(hundreds)
        up_to_thousand_in_english_sstream << ones_in_english(hundreds) << " hundred";
    if(number / 100 && number % 100)
        up_to_thousand_in_english_sstream << " ";
    up_to_thousand_in_english_sstream << up_to_hundred_in_english(number % 100);
    return up_to_thousand_in_english_sstream.str();    
}

std::string number_class_in_english(std::int64_t number_class) {
    assert(number_class >= 0 && number_class < 4 && "Wrong number class");
    const static std::array<std::string_view, 4> classes{"", " thousand", " million", " billion"};
    return std::string{classes[number_class]};
}

} // namespace
namespace say {

std::string in_english(std::int64_t number) {
    if(number < 0 || number > 999'999'999'999)
        throw std::domain_error("You are wrong!");

    if(number == 0)
        return ones_in_english(number);

    std::vector<std::string> in_english_parts{};
    auto number_class{0};
    
    while(number) {
        if(!in_english_parts.empty() && number % 1000)
            in_english_parts.emplace_back(" ");
        if(number % 1000) {
            std::string temp{};
            temp += up_to_thousand_in_english(number % 1000);
            temp += number_class_in_english(number_class);
            in_english_parts.emplace_back(std::move(temp));
        }
        ++number_class;
        number /= 1000;
    }
    return std::accumulate(std::rbegin(in_english_parts), std::rend(in_english_parts), std::string{}, [](std::string result, const std::string& part) { return std::move(result) + part; });   
}

}  // namespace say
