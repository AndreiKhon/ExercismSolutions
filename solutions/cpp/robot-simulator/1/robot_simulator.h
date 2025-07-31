#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H

#include <string_view>

namespace robot_simulator {
    enum class Bearing {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    template <typename T, typename U = T>
    using Coords = std::pair<T, U>;

    using Robot_Coords = Coords<int>;

    class Robot {
    public:
        Robot();
        Robot(Coords<int>, Bearing);
        void turn_left();
        void turn_right();
        void advance();
        void execute_sequence(std::string_view);
        Robot_Coords get_position() const;
        Bearing get_bearing() const;
    private:
        mutable Bearing bearing_;
        mutable Robot_Coords coords_;
    };
}  // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H