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
    template<class U>
    void push(U&& entry);
    T pop();
    void reverse();

    struct iterator;
    iterator begin() const { return head.get(); }
    iterator end() const { return nullptr; }
   private:
    struct Element {
        Element(T data): data{std::forward<T>(data)} {}
        T data{};
        std::unique_ptr<Element> next{};
    };
    std::unique_ptr<Element> head{};
    std::size_t current_size{};
};

template<class T>
struct List<T>::iterator {
   private:
    iterator() = default;
    iterator(Element* p_element): p_element(p_element) {}
    Element* p_element{};
    friend iterator List<T>::begin() const;
    friend iterator List<T>::end() const;
   public:
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using iterator_category = std::forward_iterator_tag;
    iterator operator++() { p_element = p_element->next.get(); return p_element; }
    iterator operator++(int) { auto p_old_element{p_element}; p_element = p_element->next.get(); return p_old_element;}
    bool operator==(const iterator& it) { return this->p_element == it.p_element; }
    bool operator!=(const iterator& it) { return !(*this == it); }
    const Element& operator*() { return *p_element; }
    Element* operator->() { return p_element; }
};

template<class T>
List<T>::List(std::initializer_list<T> i_list) {
    for(auto it{std::rbegin(i_list)}; it != std::rend(i_list); ++it) {
        push(*it);
    }
}

template<class T>
std::size_t List<T>::size() const {
    return current_size;
}

template<class T> template<class U>
void List<T>::push(U&& entry) {
    static_assert(std::is_same_v<T, std::decay_t<U>>);
    auto element{std::make_unique<Element>(std::forward<U>(entry))};
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
