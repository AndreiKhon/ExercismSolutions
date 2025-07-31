#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <string_view>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
namespace grade_school {
    class school {
        std::multimap<int, std::string> students;
    public:
        void add(std::string name, int grade) {
            students.insert({grade, name});
        }
        std::map<int, std::vector<std::string>> roster() const {
            std::map<int, std::vector<std::string>> roster_;
            for(auto it = students.begin(); it != students.end(); it = students.upper_bound(it->first)) {
                auto grade_ = it->first;
                auto specified_students = grade(grade_);
                roster_.insert({grade_, specified_students});
            }
            return roster_;
        }
        std::vector<std::string> grade(int grade_) const {
            auto [begin, end] = students.equal_range(grade_);
            std::vector<std::string> specified_students{};
            if(begin != students.end()) {
                specified_students.reserve(std::distance(begin, end));
                for(auto it = begin; it != end; it = std::next(it)) {
                    
                   
 specified_students.emplace_back(it->second);
                    }
            }
            std::sort(specified_students.begin(), specified_students.end());
            return specified_students;
        }
        
        
    };
}  // namespace grade_school

#endif // GRADE_SCHOOL_H 