#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H
#include "node.h"

template <typename T>
class queue{
public:
    queue() = default;
    queue(const queue& other) = default;
    queue(const queue&& other) = default;
    queue& operator =(const queue& other) = default;
    queue& operator =(const queue&& other) = default;

    ~queue() = default;

    void enqueue(T value);
    void enqueue(const T& value);
    void dequeue();
    void clear();
    void reserve(size_t capacity);
    void emplace(size_t size, ...);

    T& front();
    bool empty() const;
    size_t size() const;

private:
};

#endif //DATA_STRUCTURE_QUEUE_H
