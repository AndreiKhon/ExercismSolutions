#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H
#include <random>

namespace robot_name {

static std::random_device rd{};
static std::mt19937 rng{rd()}; 

inline unsigned char generateLetter() {
    static std::uniform_int_distribution<int> uid(0, 25);
    return 'A' + uid(rng);
}
inline int generateDigit() {
    static std::uniform_int_distribution<int> uid(0, 9);
    return '0' + uid(rng);
}

class robot {
public:
    robot() { reset(); }
    std::string name() const { return name_; }
    void reset() { name_.clear(); generateName(); }
private:
    void generateName() {
        name_.reserve(5);        
        auto firstLetter = generateLetter();
        auto secondLetter = generateLetter();
        auto firstDigit = generateDigit();
        auto secondDigit = generateDigit();
        auto thirdDigit = generateDigit();
        name_.push_back(firstLetter);
        name_.push_back(secondLetter);
        name_.push_back(firstDigit);
        name_.push_back(secondDigit);
        name_.push_back(thirdDigit);
    }
    std::string name_{};
};
}  // namespace robot_name

#endif // ROBOT_NAME_H