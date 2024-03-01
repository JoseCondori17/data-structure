#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H
#include "node.h"
#include <cstdarg>

template <typename T>
class stack{
public:
    typedef node::SingleNode<T> node;
public:
    stack() = default;
    stack(const stack& other) = default;
    stack(const stack&& other) = default;
    stack& operator =(const stack& other) = default;
    stack& operator =(const stack&& other) = default;

    ~stack() = default;

    void push(T value);
    void pop();
    void clear();
    void reserve(size_t capacity);
    void emplace(size_t size, ...);

    T& top();
    bool empty();
    size_t size();
private:
    node* head;
    size_t _size{};
};

template <typename T> stack<T>::stack(){
    this->head = nullptr;
    this->_size = 0;
}
template <typename T> void stack<T>::push(T value){
    node* new_node = new node(value);
    new_node->next = head;
    head = new_node;
}
template <typename T> void stack<T>::pop(){
    if (!empty){
        node* current = head;
        head = head->next;
        delete current;
    } else {
        std::cerr << "Stack is empty" << std::endl;
    }
}
template <typename T> void stack<T>::clear(){
    while (head != nullptr){
        node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    _size = 0;
}
/* review */
template <typename T> void stack<T>::reserve(size_t capacity){
    size_t i = 0;
    while (i < capacity){
        i += 1;
    }
    
}
template <typename T> void stack<T>::emplace(size_t size, ...){
    std::va_list args;
    va_start(args, size);
    for (size_t i = 0; i < size; ++i){
        push(va_arg(args, T));
    }
    va_end(args);
}   
template <typename T> T& stack<T>::top(){
    if (!empty){
        return head->data;
    } else {
        return T();
    }
}
template <typename T> bool stack<T>::empty(){
    return head == nullptr;
}
template <typename T> size_t stack<T>::size(){
    return _size;
}

#endif //DATA_STRUCTURE_STACK_H
