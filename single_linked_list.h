#ifndef DATA_STRUCTURE_SINGLE_LINKED_LIST_H
#define DATA_STRUCTURE_SINGLE_LINKED_LIST_H
#include "node.h"
#include <cstdarg>

template <typename T>
class linked_list{
public:
    typedef node::SingleNode<T> node; // verify! -- typedef node::SingleNode<T>* node;
private:
    node* head;
    node* tail;
    size_t _size{};
public:
    linked_list();
    ~linked_list();

    linked_list(const linked_list<T>&) = default;
    linked_list& operator =(const linked_list<T>&)=default;

    linked_list(linked_list<T>&&)=default;
    linked_list& operator =(linked_list<T>&&)=default;

    T front();
    T back();
    void push_front(T value);
    void push_back(T value);
    void pop_front();
    void pop_back();
    void insert(T value, int position);
    void insert_sort(T value);
    void erase(int position);
    void remove(T value);
    void sort(); // Pending
    void clear();

    //void sorted();
    void reverse(); // Pending - feedback
    void unique();
    bool contains(T value);
    size_t index(T value);
    void emplace_front(size_t size, ...); // Pending - feedback
    void emplace_back(size_t size, ...);

    bool empty();
    size_t size();

    linked_list<T> operator+(linked_list& other); // union
    linked_list<T> operator-(linked_list& other); // difference
    T& operator[](int position); // get value or change value

    template <typename U> friend std::ostream& operator<<(std::ostream& out, linked_list<U>& other);
};

/* -------------------------------- DEVELOPMENT ------------------------------------------ */

template <typename T> linked_list<T>::linked_list() {
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;
}
template <typename T> linked_list<T>::~linked_list() {
    clear();
}
template <typename T> T linked_list<T>::front() {
    if (!empty()) {
        return head->data;
    } else {
        return T();
    }
}
template <typename T> T linked_list<T>::back() {
    if (!empty()) {
        return tail->data;
    } else {
        return T();
    }
}
template <typename T> void linked_list<T>::push_front(T value) {
    auto* new_node = new node(value);
    if (!empty()){
        new_node->next = head;
        head = new_node;
    } else {
        head = new_node;
        tail = new_node;
    }
    _size += 1;
}
template <typename T> void linked_list<T>::push_back(T value) {
    auto* new_node = new node(value);
    if (!empty()){
        tail->next = new_node;
        tail = new_node;
    } else {
        head = new_node;
        tail = new_node;
    }
    _size += 1;
}
template <typename T> void linked_list<T>::pop_front() {
    if (!empty()) {
        if (head->next != nullptr) {
            node* current = head;
            head = head->next;
            delete current;
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
template <typename T> void linked_list<T>::pop_back() {
    if (!empty()) {
        if (head->next != nullptr) {
            node* current = head;
            while (current->next->next != nullptr){
                current = current->next;
            }
            delete current->next;
            tail = current;
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
template <typename T> void linked_list<T>::insert(T value, int position) {
    if (empty()) {
        std::cerr << "List is empty" << std::endl;
    } else if (position >= _size || position < 0) {
        std::cerr << "Index out of range" << std::endl;
    } else {
        if (position == 0) {
            push_front(value);
        } else {
            auto* new_node = new node(value);
            node* current = head;
            while (current->next->next && position > 0){
                current = current->next;
                position -= 1;
            }
            new_node->next = current->next;
            current->next = new_node;
            _size += 1;
        }
    }
}
// verify ......................................................
template <typename T> void linked_list<T>::insert_sort(T value) {
    auto* new_node = new node(value);
    if (!empty()) {
        node* current = head;
        while (current->next && current->next->data < value){
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    } else {
        head = new_node;
        tail = new_node;
    }
    _size += 1;
}
template <typename T> void linked_list<T>::erase(int position) {
    if (empty()) {
        std::cerr << "List is empty" << std::endl;
    } else if (position >= _size || position < 0) {
        std::cerr << "Index out of range" << std::endl;
    } else {
        if (position == 0){
            pop_front();
        } else if (position == _size - 1) {
            pop_back();
        } else {
            node* current = head;
            node* temp;
            while ((position - 1 ) > 0){
                current = current->next;
                position -= 1;
            }
            temp = current->next;
            current->next = current->next->next;
            delete temp;
            _size -= 1;
        }
    }
}
template <typename T> void linked_list<T>::remove(T value) {
    if (!empty()) {
        if (head->data == value){
            pop_front();
        } else if (tail->data == value){
            pop_back();
        } else {
            node* current = head;
            node* temp;
            while (current->next && current->next->data != value){
                current = current->next;
            }
            temp = current->next;
            current = current->next->next;
            delete temp;
            _size -= 1;
        }
    } else {
        std::cerr << "List is empty" << std::endl;
    }
}
template <typename T> void linked_list<T>::sort() {
    // bubble sort - pending
}
template <typename T> void linked_list<T>::clear() {
    while (head != nullptr){
        node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    _size = 0;
}
template <typename T> void linked_list<T>::reverse() {
    // pending - feedback
    if (empty()) {
        std::cerr << "List is empty" << std::endl;
    } else {
        node* current = head;
        node* previous = nullptr;
        node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        tail = head;
        head = previous;
    }
}
template <typename T> void linked_list<T>::unique() {
    if (!empty()){
        node* current = head;
        node* runner = head;
        while (current != nullptr){
            while (runner->next){
                if (runner->next->data == current->data){
                    node* temp = runner->next;
                    runner->next = runner->next->next;
                    delete temp;
                    _size -= 1;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    } else {
        std::cerr << "List is empty" << std::endl;
    }
}
template <typename T> bool linked_list<T>::contains(T value) {
    node* current = head;
    while (current != nullptr){
        if (current->data == value)
            return true;
        current = current->next;
    }
    return false;
}
template <typename T> size_t linked_list<T>::index(T value) {
    size_t position = 0;
    node* current = head;
    while (current != nullptr){
        if (current->data == value)
            return position;
        position += 1;
        current = current->next;
    }
    return -1;
}
template <typename T> void linked_list<T>::emplace_front(size_t size, ...) {
    std::va_list args;
    va_start(args, size);
    for (size_t i = 0; i < size; ++i){
        push_front(va_arg(args, T));
    }
    va_end(args);
}
template <typename T> void linked_list<T>::emplace_back(size_t size, ...) {
    std::va_list args;
    va_start(args, size);
    for (int i = 0; i < size; ++i){
        push_back(va_arg(args, T));
    }
    va_end(args);
}
template <typename T> bool linked_list<T>::empty() {
    return head == nullptr;
}
template <typename T> size_t linked_list<T>::size() {
    return _size;
}
template <typename T> linked_list<T> linked_list<T>::operator+(linked_list<T> &other) {
    linked_list<T> new_list;
    node* current;

    // first list
    current = this->head;
    while (current != nullptr){
        new_list.push_back(current->data);
        current = current->next;
    }
    // second list
    current = other.head;
    while (current != nullptr){
        new_list.push_back(current->data);
        current = current->next;
    }
}
template <typename T> linked_list<T> linked_list<T>::operator-(linked_list<T> &other) {
    // if ordered complexity is O(n)
    linked_list<T> new_list;
    node* current = head;
    while (current != nullptr){
        if (!other.contains(current->data))
            new_list.push_back(current->data);
        current = current->next;
    }
}
template <typename T> T &linked_list<T>::operator[](int position) {
    if (empty()) {
        std::cerr << "List is empty" << std::endl;
    } else if (position >= _size || position < 0){
        std::cerr << "Index out of range" <<  std::endl;
    } else {
        node* current = head;
        while (position > 0){
            current = current->next;
            position -= 1;
        }
        return current->data;
    }
}
template <typename T> std::ostream& operator<<(std::ostream& out, linked_list<T>& other){
    node::SingleNode<T>* current = other.head;
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

#endif //DATA_STRUCTURE_SINGLE_LINKED_LIST_H
