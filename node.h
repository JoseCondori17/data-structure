#ifndef DATA_STRUCTURE_NODE_H
#define DATA_STRUCTURE_NODE_H
#include <iostream>

namespace node {
    template<typename T>
    struct SingleNode {
        T data;
        SingleNode *next;

        SingleNode() : data(T()), next(nullptr) {}
        explicit SingleNode(const T &value) : data(value), next(nullptr) {}
    };

    template<typename T>
    struct DoubleNode {
        T data;
        DoubleNode *next;
        DoubleNode *prev;
        DoubleNode() : data(T()), next(nullptr), prev(nullptr) {}
        explicit DoubleNode(const T &value) : data(value), next(nullptr), prev(nullptr) {}
    };

    template<typename T>
    struct TreeNode {
        T data;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : data(T()), left(nullptr), right(nullptr) {}
        explicit TreeNode(const T &value) : data(value), left(nullptr), right(nullptr) {}
    };
};
#endif //DATA_STRUCTURE_NODE_H
