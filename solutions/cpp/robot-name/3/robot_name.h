#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H
#include <string>
#include <unordered_set>

namespace robot_name {

class robot {
public:
    robot();
    std::string name() const;
    void reset();
private:
    robot(const robot&) = delete;
    robot& operator=(const robot&) = delete;
    unsigned char generateLetter() const;
    unsigned char generateDigit() const;
    void generateName();
    std::string name_{};
    static std::unordered_set<std::string> takenNames;
};
}  // namespace robot_name 

#endif // ROBOT_NAME_H