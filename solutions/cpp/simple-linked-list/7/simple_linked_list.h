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
    template<class U,
             class = std::enable_if_t<std::is_same_v<T, std::decay_t<U>>>>
    void push(U&& entry);
    T pop();
    void reverse();

    class const_iterator;
    using iterator = const_iterator;
    const_iterator begin() const { return const_iterator{head.get()}; }
    const_iterator end() const { return {}; }
    const_iterator cbegin() const { return begin(); }
    const_iterator cend() const { return end(); }
   private:
    struct Element {
        template<class U,
             class = std::enable_if_t<std::is_same_v<T, std::decay_t<U>>>>
        Element(U&& data): data{std::forward<U>(data)} {}
        T data{};
        std::unique_ptr<Element> next{};
    };
    std::unique_ptr<Element> head{};
    std::size_t current_size{};
};

template<class T>
class List<T>::const_iterator {
   public:
    using difference_type = std::ptrdiff_t;
    using value_type = const Element;
    using pointer = value_type*;
    using reference = value_type&;
    using iterator_category = std::forward_iterator_tag;

    const_iterator() = default;

    const_iterator& operator++() { p_element = p_element->next.get(); return *this; }
    const_iterator operator++(int) { auto it{*this}; ++*this; return it; }

    bool operator==(const const_iterator& it) const { return this->p_element == it.p_element; }
    bool operator!=(const const_iterator& it) const { return !(*this == it); }

    const reference operator*() const { return *p_element; }
    pointer operator->() const { return p_element; }
   private:
    explicit const_iterator(pointer p_element): p_element(p_element) {}
    pointer p_element{};
    friend const_iterator List<T>::begin() const;
    friend const_iterator List<T>::end() const;
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

template<class T> template<class U, class>
void List<T>::push(U&& entry) {
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
    auto value{std::move(head->data)};
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
