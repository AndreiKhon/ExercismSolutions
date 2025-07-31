#include "simple_linked_list.h"
#include <cassert>

namespace simple_linked_list {

auto work_with_another_type() {
    List<double> list{};
    list.push(3.14159);
    list.push(9.81);
    assert(list.size() == 2);
    [[maybe_unused]] auto value{list.pop()};
    assert(value - 9.81 < 0.01);
    list.reverse();
    assert(list.size() == 1);
    return 'a';
}

auto work_with_intializer_list() {
    std::initializer_list<int> i_list{0, 1, 2};
    [[maybe_unused]] List list_a(i_list);
    [[maybe_unused]] List list_b{0, 1, 2};
    List list_c{{0, 1, 2}};
    for(int i{}; i < 3; ++i) {
        assert(list_c.pop() == i);
    }
    return 'b';
}

auto work_with_for_loop() {
    List list{0, 1, 2};
    auto counter{0};
    for(auto it{list.begin()}; it != list.end(); ++it) {
        assert(*it == counter++);
    }
    return 'c';
}

auto work_with_range_for() {
    List list{0, 1, 2};
    auto counter{0};
    for(const auto& value: list) {
        assert(value == counter++);
    }
    return 'd';
}

auto work_with_move_only_types() {
    struct foo {
        int i_{};
        foo(int i) : i_{i} {}
        foo(const foo&) = delete;
        foo(foo&&) = default;
        foo& operator=(const foo&) = delete;
        foo& operator=(foo&&) = default;
    };

    List<foo> list;
    list.push(foo{42});

    return 'e';
}

volatile auto work_with_another_type_{work_with_another_type()};
volatile auto work_with_intializer_list_{work_with_intializer_list()};
volatile auto work_with_for_loop_{work_with_for_loop()};
volatile auto work_with_range_for_{work_with_range_for()};
volatile auto work_with_move_only_types_{work_with_move_only_types()};

}  // namespace simple_linked_list
