#ifndef DATA_STRUCTURE_DOUBLY_LINKED_LIST_H
#define DATA_STRUCTURE_DOUBLY_LINKED_LIST_H
#include "node.h"

template <typename T>
class doubly_linked_list{
public:
    typedef node::DoubleNode<T> node; 
private:
    node* head;
    node* tail;
    size_t _size{};
public:
    doubly_linked_list();
    ~doubly_linked_list();

    doubly_linked_list(const linked_list<T>&) = default;
    doubly_linked_list& operator =(const linked_list<T>&)=default;

    doubly_linked_list(doubly_linked_list<T>&&)=default;
    doubly_linked_list& operator =(doubly_linked_list<T>&&)=default;

    T front();
    T back();
    void push_front(T value);
    void push_back(T value);
    void pop_front();
    void pop_back();
    void insert(T value,unsigned position);
    void insert_sort(T value);
    void erase(unsigned position);
    void remove(T value);
    void sort(); // Pending
    void clear();

    //void sorted();
    void reverse();
    void unique();
    bool contains(T value);
    size_t index(T value);
    void emplace_front(size_t size, ...);
    void emplace_back(size_t size, ...);

    bool empty();
    size_t size();

    //linked_list<T> operator+(linked_list& other); // union
    //linked_list<T> operator-(linked_list& other); // difference
    T& operator[](int position); // get value or change value

    template <typename U> friend std::ostream& operator<<(std::ostream& out, doubly_linked_list<U>& other);
};

template <typename T> doubly_linked_list<T>::doubly_linked_list(){
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;
}
template <typename T> doubly_linked_list<T>::~doubly_linked_list(){
    this->clear();
}
template <typename T> T doubly_linked_list<T>::front(){
    if (!empty()){
        return head->data;
    } else {
        throw std::out_of_range("List is empty");
    }
}
template <typename T> T doubly_linked_list<T>::back(){
    if (!empty()){
        return tail->data;
    } else {
        throw std::out_of_range("List is empty");
    }
}
template <typename T> void doubly_linked_list<T>::push_front(T value){
    auto* new_node = new node(value);
    if (!empty()){
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    } else {
        head = new_node;
        tail = new_node;
    }
    _size += 1;
}
template <typename T> void doubly_linked_list<T>::push_back(T value){
    auto* new_node = new node(value);
    if (!empty()){
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    } else {
        head = new_node;
        tail = new_node;
    }
    _size += 1;
}
template <typename T> void doubly_linked_list<T>::pop_front(){
    if (!empty()){
        if (head->next){
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        } else {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        _size -= 1;
    } else {
        std::cerr << "List is empty" << std::endl;
    }
}
template <typename T> void doubly_linked_list<T>::pop_back(){
    if (!empty()){
        if (head->next){
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        } else {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        _size -= 1;
    } else {
        std::cerr << "List is empty" << std::endl;
    }
}
template <typename T> void doubly_linked_list<T>::insert(T value,unsigned position){
    if (empty()){
        throw std::out_of_range("List is empty");
    } else if (position >= _size || position < 0) {
        throw std::out_of_range("Index out of range");        
    } else {
        if (position == 0){
            push_front(value);  
        } else {
            auto* new_node = new node(value);
            node* current = head;
            while (current->next && position > 0){
                current = current->next;
                position -= 1;
            }
            new_node->next = current->next;
            new_node->prev = current;
            current->next->prev = new_node;
            current->next = new_node;
            _size += 1;
        }
    }
}
template <typename T> void doubly_linked_list<T>::insert_sort(T value){}
template <typename T> void doubly_linked_list<T>::erase(unsigned position){}
template <typename T> void doubly_linked_list<T>::remove(T value){}
template <typename T> void doubly_linked_list<T>::sort(){}
template <typename T> void doubly_linked_list<T>::clear(){
    while (head){
        head = head->next;
        delete head->prev;
    }
    tail = nullptr;
}

template <typename T> void doubly_linked_list<T>::reverse(){}
template <typename T> void doubly_linked_list<T>::unique(){}
template <typename T> bool doubly_linked_list<T>::contains(T value){
    node* current = head;
    while (current){
        if (current->data == value)
            return true;
        current = current->next;
    }
    return false;
}
template <typename T> size_t doubly_linked_list<T>::index(T value){}
template <typename T> void doubly_linked_list<T>::emplace_front(size_t size, ...){
    va_list args;
    
}
template <typename T> void doubly_linked_list<T>::emplace_back(size_t size, ...){}

template <typename T> bool doubly_linked_list<T>::empty(){
    return head == nullptr;
}
template <typename T> size_t doubly_linked_list<T>::size(){
    return _size;
}

#endif //DATA_STRUCTURE_DOUBLY_LINKED_LIST_H
