#include "robot_simulator.h"

namespace robot_simulator {
    Robot::Robot():
        bearing_(Bearing::NORTH), coords_({0, 0}) {
        
    }
    Robot::Robot(Coords<int> coords, Bearing bearing): 
        bearing_(bearing), coords_(coords) {
        
    }

    void Robot::turn_left() {
        switch(bearing_) {
            case Bearing::NORTH:
                bearing_ = Bearing::WEST;
                break;
            case Bearing::EAST:
                bearing_ = Bearing::NORTH;
                break;
            case Bearing::SOUTH:
                bearing_ = Bearing::EAST;
                break;
            case Bearing::WEST:
                bearing_ = Bearing::SOUTH;
                break;
        }
    }

    void Robot::turn_right() {
        switch(bearing_) {
            case Bearing::NORTH:
                bearing_ = Bearing::EAST;
                break;
            case Bearing::EAST:
                bearing_ = Bearing::SOUTH;
                break;
            case Bearing::SOUTH:
                bearing_ = Bearing::WEST;
                break;
            case Bearing::WEST:
                bearing_ = Bearing::NORTH;
                break;
        }
    }

    void Robot::advance() {
        auto& [x, y] = coords_;
        switch(bearing_) {
            case Bearing::NORTH:
                ++y;
                break;
            case Bearing::EAST:
                ++x;
                break;
            case Bearing::SOUTH:
                --y;
                break;
            case Bearing::WEST:
                --x;
                break;
        }
    }

    void Robot::execute_sequence(std::string_view sequence) {
        for(auto ch: sequence) {
            switch(ch) {
                case 'R':
                    turn_right();
                    break;
                case 'L':
                    turn_left();
                    break;
                case 'A':
                    advance();
                    break;
            }
        }
    }

    Robot_Coords Robot::get_position() const {
        return coords_;
    }

    Bearing Robot::get_bearing() const {
        return bearing_;
    }

}  // namespace robot_simulator
