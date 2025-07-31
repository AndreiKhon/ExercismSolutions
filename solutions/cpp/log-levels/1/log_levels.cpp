#include <string>
#include <string_view>
#include <cctype>
#include <algorithm>

namespace log_line {
std::string message(std::string_view str) {
    auto pos = str.find(":");
    return std::string{str.substr(pos + 2)};
}
std::string log_level(std::string_view str) {
    auto pos = str.find("]");
    auto log_level_ = str.substr(1, pos - 1);
    std::for_each(log_level_.begin(), log_level_.end(), [](unsigned char ch) { return toupper(ch); });
    return std::string{log_level_};
}
std::string reformat(std::string_view str) {
    auto message_{message(str)};
    message_ += " (";
    message_ += log_level(str);
    message_ += ")";
    return message_;
}
} // namespace log_line
