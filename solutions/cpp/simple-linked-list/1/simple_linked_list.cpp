#include "simple_linked_list.h"

#include <stdexcept>
#include <iostream>
namespace simple_linked_list {

auto work_with_another_type() {
    List<double> list{};
    list.push(3.14159);
    list.push(9.81);
    [[maybe_unused]] auto value{list.pop()};
    list.reverse();
    return 'a';
}

volatile auto work_with_another_type_{work_with_another_type()};

}  // namespace simple_linked_list
