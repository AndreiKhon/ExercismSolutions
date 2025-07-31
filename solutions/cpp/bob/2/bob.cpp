#include "bob.h"
#include <algorithm>
#include <cctype>

namespace bob {

    bool isYell(std::string_view str) {
        auto hasLetter = std::any_of(begin(str), end(str), [](unsigned char ch) { return isalpha(ch); });
        auto hasOnlyCapitals = std::none_of(begin(str), end(str), [](unsigned char ch){ return islower(ch); });
        return hasLetter && hasOnlyCapitals;
    }

    std::string_view trim(std::string_view str) {
        using namespace std::literals;
        auto spaces = " \t\r\n"sv;
        
        auto index = str.find_first_not_of(spaces);
        if(index == std::string_view::npos) {
            str.remove_prefix(str.size());
            return str;
        }
        str.remove_prefix(index);

        index = str.find_last_not_of(spaces);
        str.remove_suffix(str.size() - index - 1);
        return str;
    }

    std::string hey(std::string_view str) {
        str = trim(str);
        if(str.empty())
            return "Fine. Be that way!";
        auto isQuestion = [](std::string_view str) { return str.back() == '?'; }; //Only for trimmed and not empty strings
        auto isQuestion_ = isQuestion(str);
        auto isYell_ = isYell(str);
        if(isQuestion_ && !isYell_)
            return "Sure.";
        if(!isQuestion_ && isYell_)
            return "Whoa, chill out!";
        if(isQuestion_ && isYell_)
            return "Calm down, I know what I'm doing!";
        return "Whatever.";
    }
}  // namespace bob
