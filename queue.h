#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H
#include "node.h"
#include <cstdarg>

template <typename T>
class linked_queue{
public:
    typedef node::SingleNode<T> node;
public:
    linked_queue();
    ~linked_queue();

    //queue(const queue& other) = default;
    //queue(const queue&& other) = default;
    //queue& operator =(const queue& other) = default;
    //queue& operator =(const queue&& other) = default;

    void enqueue(T value);
    void dequeue();
    void clear();
    void emplace(size_t size, ...);

    T& front();
    bool empty() const;
    size_t size() const;
    
    template <typename U> friend std::ostream& operator<<(std::ostream& out, linked_queue<U>& other);
private:
    node* _back;
    node* _front;
};

template <typename T> linked_queue<T>::linked_queue(){
    this->_front = nullptr;
    this->_back = nullptr;
}
template <typename T> linked_queue<T>::~linked_queue(){
    this->clear();
}
template <typename T> void linked_queue<T>::enqueue(T value){
    auto* new_node = new node(value);
    if (!empty()){
        _back->next = new_node;
        _back = new_node;
    } else {
        _front = new_node;
        _back = new_node;
    }
}
template <typename T> void linked_queue<T>::dequeue(){
    if (!empty()){
        node* current = _front;
        _front = _front->next;
        delete current;
    } else {
        std::cerr << "Queue is empty" << std::endl;
    }
}
template <typename T> void linked_queue<T>::clear(){
    while (_front){
        node* temp = _front;
        _front = _front->next;
        delete temp;
    }
    _back = nullptr;
}
template <typename T> void linked_queue<T>::emplace(size_t size, ...){
    std::va_list args;
    va_start(args, size);
    for (size_t i = 0; i < size; ++i){
        enqueue(va_arg(args, T));
    }
    va_end(args);
}   
template<class T> T& linked_queue<T>::front() {
    if (!empty()){
        return _front->data;
    } else {
        throw std::out_of_range("Queue is empty");
    }
}
template <typename T> bool linked_queue<T>::empty() const {
    return _front == nullptr;
}
template <typename T> size_t linked_queue<T>::size() const {
    size_t size = 0;
    node* current = _front;
    while (current){
        size += 1;
        current = current->next;
    }
    return size;
}
template <typename T> std::ostream& operator<<(std::ostream& out, linked_queue<T>& other){
    node::SingleNode<T>* current = other._front;
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

#endif //DATA_STRUCTURE_QUEUE_H
