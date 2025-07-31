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

    using Robot_Coords = Coords<int, int>;

    class Robot {
    public:
        Robot() = default;
        Robot(Robot_Coords, Bearing);
        void turn_left();
        void turn_right();
        void advance();
        void execute_sequence(std::string_view);
        [[nodiscard]] Robot_Coords get_position() const;
        [[nodiscard]] Bearing get_bearing() const;
    private:
        mutable Bearing bearing_ = Bearing::NORTH;
        mutable Robot_Coords coords_ = {0, 0};
    };
}  // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H