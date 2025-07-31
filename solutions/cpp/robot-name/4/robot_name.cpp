#include "robot_name.h"
#include <random>
#include <stdexcept>

namespace robot_name {

static std::random_device rd{};
static std::mt19937 rng{rd()}; 

std::unordered_set<std::string> robot::takenNames{};

unsigned char robot::generateLetter() const {
    static std::uniform_int_distribution<int> uid(0, 25);
    return 'A' + uid(rng);
}
unsigned char robot::generateDigit() const {
    static std::uniform_int_distribution<int> uid(0, 9);
    return '0' + uid(rng);
}

robot::robot() { 
    name_.reserve(5);
    reset(); 
}

std::string robot::name() const { 
    return name_; 
}

void robot::reset() { 
    //takenNames.erase(name_);
    generateName(); 
}

void robot::generateName() {
    constexpr static auto maxNamesCount = 26 * 26 * 10 * 10 * 10;
    if(takenNames.size() == maxNamesCount)
        throw std::domain_error("The number of names has been exhausted");
    auto isInserted{false};
    do {
        name_.clear(); 
        name_.push_back(generateLetter());
        name_.push_back(generateLetter());
        name_.push_back(generateDigit());
        name_.push_back(generateDigit());
        name_.push_back(generateDigit());
        std::tie(std::ignore, isInserted) = takenNames.insert(name_); 
    } while(!isInserted);
}

}  // namespace robot_name 
