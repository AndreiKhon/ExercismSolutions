#if !defined(SIMPLE_LINKED_LIST_H)
#define SIMPLE_LINKED_LIST_H

#include <stdexcept>
#include <cstddef>
#include <memory>
#include <initializer_list>
		
namespace simple_linked_list {

template<class T = int>
class List {
   public:
    List() = default;
    ~List() = default;

    List(std::initializer_list<T>);
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

    struct Element {
        Element(const T& data): data(data) {}
        T data{};
        std::shared_ptr<Element> next{};
    };

    struct iterator {
        iterator(Element* p_element): p_element(p_element) {}
        Element* p_element{};
        Element* operator++() { p_element = p_element->next.get(); return p_element; }
        bool operator==(const iterator& it) { return this->p_element == it.p_element; }
        bool operator!=(const iterator& it) { return !(*this == it); }
        const Element& operator*() { return *p_element; }
        Element* operator->() { return p_element; }
    };

    iterator begin() { return head.get(); }
    iterator end() { return nullptr; }
   private:
    std::shared_ptr<Element> head{};
    std::size_t current_size{};
};

template<class T>
List<T>::List(std::initializer_list<T> i_list) {
    for(auto it{rbegin(i_list)}; it != rend(i_list); ++it) {
        push(*it);
    }
}

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
    if(current_size == 0)
        throw std::domain_error("Pop with empty list");
    auto element{std::move(head->next)};
    auto value{head->data};
    head = std::move(element);
    --current_size;
    return value;
}

template<class T>
void List<T>::reverse() {
    std::shared_ptr<Element> prev{};
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
