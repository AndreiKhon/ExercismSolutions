#include "bob.h"
#include <algorithm>
#include <cctype>
namespace bob {
    bool isSilence(std::string_view str) {
        for(unsigned char ch: str) {
            if(!std::isspace(ch))
                return false;
        }
        return true;
    }

    bool isQuestion(std::string_view str) {
        if(str.empty())
            return false;
        for(auto it = std::crbegin(str); it != std::crend(str); ++it) {
            unsigned char ch = *it;
            if(!std::isspace(ch)) {
                if(ch == '?')
                    return true;
                return false;
            }
        }
        return false;
    }

    bool isYell(std::string_view str) {
        auto lettersCount{0};
        for(unsigned char ch: str) {
            if(std::isalpha(ch)) {
                ++lettersCount;
                if(std::islower(ch))
                    return false;
            }
        }
        return lettersCount != 0;
    }

    std::string hey(std::string_view str) {
        auto isSilence_ = isSilence(str);
        if(isSilence_)
            return "Fine. Be that way!";
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
