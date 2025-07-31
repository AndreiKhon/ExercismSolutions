#if !defined(ISOGRAM_H)
#define ISOGRAM_H
#include <string_view>
namespace isogram {
    bool is_isogram(std::string_view word);
}  // namespace isogram

#endif // ISOGRAM_H