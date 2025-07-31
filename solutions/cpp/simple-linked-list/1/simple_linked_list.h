#if !defined(SIMPLE_LINKED_LIST_H)
#define SIMPLE_LINKED_LIST_H

#include <cstddef>
#include <memory>
namespace simple_linked_list {

template<class T = int>
class List {
   public:
    List() = default;
    ~List() = default;

    // Moving and copying is not needed to solve the exercise.
    // If you want to change these, make sure to correctly
    // free / move / copy the allocated resources.
    List(const List&) = delete;
    List& operator=(const List&) = delete;
    List(List&&) = delete;
    List& operator=(List&&) = delete;

    std::size_t size() const;
    void push(T entry);
    T pop();
    void reverse();
   private:
    struct Element {
        Element(const T& data): data(data) {}
        T data{};
        std::unique_ptr<Element> next{};
    };
    std::unique_ptr<Element> head{};
    std::size_t current_size{};
};

template<class T>
std::size_t List<T>::size() const {
    return current_size;
}

template<class T>
void List<T>::push(T entry) {
    auto element{std::make_unique<Element>(entry)}; // Should i use make_unique?
    element->next = std::move(head);
    head = std::move(element);
    ++current_size;
}

template<class T>
T List<T>::pop() {
    auto element{std::move(head->next)};
    auto value{head->data};
    head = std::move(element);
    --current_size;
    return value;
}

template<class T>
void List<T>::reverse() {
    std::unique_ptr<Element> prev{};
    while(head) {
        auto next{std::move(head->next)};
        head->next = std::move(prev);
        prev = std::move(head);
        head = std::move(next);
    }
    head = std::move(prev);
}

}  // namespace simple_linked_list

#endif
