#if !defined(ETL_H)
#define ETL_H
#include <map>
#include <vector>
#include <cctype>
namespace etl {
    inline std::map<char, int> transform(const std::map<int, std::vector<char>> old) {
        std::map<char, int> new_system{};
        for(const auto& [key, old_values]: old) {
            for(auto value: old_values)
                new_system.insert({std::tolower(value), key});
        }
        return new_system;
    }
}  // namespace etl

#endif // ETL_H