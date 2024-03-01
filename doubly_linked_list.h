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
    void view_structure();
};

template <typename T> doubly_linked_list<T>::doubly_linked_list(){}
template <typename T> T doubly_linked_list<T>::front(){}
template <typename T> T doubly_linked_list<T>::back(){}
template <typename T> void doubly_linked_list<T>::push_front(T value){}
template <typename T> void doubly_linked_list<T>::push_back(T value){}
template <typename T> void doubly_linked_list<T>::pop_front(){}
template <typename T> void doubly_linked_list<T>::pop_back(){}
template <typename T> void doubly_linked_list<T>::insert(T value,unsigned position){}
template <typename T> void doubly_linked_list<T>::insert_sort(T value){}
template <typename T> void doubly_linked_list<T>::erase(unsigned position){}
template <typename T> void doubly_linked_list<T>::remove(T value){}
template <typename T> void doubly_linked_list<T>::sort(){}
template <typename T> void doubly_linked_list<T>::clear(){}

template <typename T> void doubly_linked_list<T>::reverse(){}
template <typename T> void doubly_linked_list<T>::unique(){}
template <typename T> bool doubly_linked_list<T>::contains(T value){}
template <typename T> size_t doubly_linked_list<T>::index(T value){}
template <typename T> void doubly_linked_list<T>::emplace_front(size_t size, ...){}
template <typename T> void doubly_linked_list<T>::emplace_back(size_t size, ...){}

template <typename T> bool doubly_linked_list<T>::empty(){}
template <typename T> size_t doubly_linked_list<T>::size(){}

#endif //DATA_STRUCTURE_DOUBLY_LINKED_LIST_H
