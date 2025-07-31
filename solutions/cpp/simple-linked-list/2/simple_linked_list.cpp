#include "simple_linked_list.h"

#include <iostream>
#include <cassert>
namespace simple_linked_list {

auto work_with_another_type() {
    List<double> list{};
    list.push(3.14159);
    list.push(9.81);
    [[maybe_unused]] auto value{list.pop()};
    list.reverse();
    return 'a';
}

auto work_with_intializer_list() {
    std::initializer_list<int> i_list{0, 1, 2};
    [[maybe_unused]] List list_a{i_list};
    [[maybe_unused]] List list_b{0, 1, 2};
    List list_c{{0, 1, 2}};
    for(int i{}; i < 3; ++i) {
        assert(list_c.pop() == i);
    }
    return 'b';
}

volatile auto work_with_another_type_{work_with_another_type()};
volatile auto work_with_intializer_list_{work_with_intializer_list()};

}  // namespace simple_linked_list
