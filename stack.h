#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H
#include "node.h"
#include <cstdarg>
// cambiar el head por top verificar eso
template <typename T>
class linked_stack{
public:
    typedef node::SingleNode<T> node;
public:
    linked_stack();
    ~linked_stack();

    //stack(const stack& other) = default;
    //stack(const stack&& other) = default;
    //stack& operator =(const stack& other) = default;
    //stack& operator =(const linked_stack&& other) = default;

    void push(T value);
    void pop();
    void clear();
    void emplace(size_t size, ...);

    T& top();
    bool empty();
    size_t size();
    
    template <typename U> friend std::ostream& operator<<(std::ostream& out, linked_stack<U>& other);
private:
    node* _top;
};

template <typename T> linked_stack<T>::linked_stack(){
    this->_top = nullptr;
}
template <typename T> linked_stack<T>::~linked_stack(){
    this->clear();
}
template <typename T> void linked_stack<T>::push(T value){
    node* new_node = new node(value);
    new_node->next = _top;
    _top = new_node;
}
template <typename T> void linked_stack<T>::pop(){
    if (!empty()){
        node* current = _top;
        _top = _top->next;
        delete current;
    } else {
        std::cerr << "Stack is empty" << std::endl;
    }
}
template <typename T> void linked_stack<T>::clear(){
    while (_top){
        node* temp = _top;
        _top = _top->next;
        delete temp;
    }
    _top = nullptr;
}
template <typename T> void linked_stack<T>::emplace(size_t size, ...){
    std::va_list args;
    va_start(args, size);
    for (size_t i = 0; i < size; ++i){
        push(va_arg(args, T));
    }
    va_end(args);
}   
template <typename T> T& linked_stack<T>::top(){
    if (!empty()){
        return _top->data;
    } else {
        throw std::out_of_range("Stack is empty");
    }
}
template <typename T> bool linked_stack<T>::empty(){
    return _top == nullptr;
}
template <typename T> size_t linked_stack<T>::size(){
    size_t size = 0;
    node* current = _top;
    while (current){
        size += 1;
        current = current->next;    
    }
    return size;
}
template <typename T> std::ostream& operator<<(std::ostream& out, linked_stack<T>& other){
    node::SingleNode<T>* current = other._top;
    size_t i = 0;

    out << "[";
    while (i < other.size()){
        if (i + 1 == other.size()){
            out << current->data;
        } else {
            out << current->data << ", ";
        }
        i += 1;
        current = current->next;
    }
    out << "]";
    return out;
}

#endif //DATA_STRUCTURE_STACK_H
