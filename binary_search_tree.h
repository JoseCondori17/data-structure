#ifndef DATA_STRUCTURE_BINARY_TREE_H
#define DATA_STRUCTURE_BINARY_TREE_H
#include "node.h"
#include <string>
#include <queue>
#include <stack>

template <typename T>
class binary_search_tree{
public:
    typedef node::TreeNode<T> node;
private:
    node* root;
public:
    binary_search_tree();
    ~binary_search_tree();

    binary_search_tree(const binary_search_tree& other) = default;
    binary_search_tree& operator=(const binary_search_tree& other) = default;

    //binary_search_tree(const binary_search_tree&& other) = default;
    //binary_search_tree& operator=(const binary_search_tree&& other) = default;

    void insert(const T& value);
    void remove(const T& value);
    void clear();

    bool empty();
    bool full();
    bool search(T value);
    bool balanced(); // missing

    std::string inorder();
    std::string preorder();
    std::string postorder();
    std::string BFS(); // breadth-first search
    std::string DFS(); // depth-first search

    size_t size();
    size_t height();

    T min_value();
    T max_value();
    T successor(T value);
    T predecessor(T value);

    // iterator begin();
    // iterator end();

private:
    void insert(node* &current, const T& value);
    void remove(node* &current, const T& value);
    void clear(node* &current);
    bool full(node* current);
    bool search(node* current, T value);
    bool balanced(node* current);
    std::string inorder(node* current);
    std::string preorder(node* current);
    std::string postorder(node* current);
    size_t size(node* current);
    size_t height(node* current);
    T min_value(node* current);
    T max_value(node* current);
    T successor(node* current, T value);
    T predecessor(node* current, T value);
};

// private methods
template <typename T> void binary_search_tree<T>::insert(node* &current, const T& value) {
    if (current == nullptr){
        current = new node(value);
    } else if (value < current->data){
        insert(current->left, value);
    } else if (value > current->data){
        insert(current->right, value);
    } else {
        return;
    }
}
template <typename T> void binary_search_tree<T>::remove(node* &current, const T& value) {
    if (current == nullptr) {
        return;
    } else if (value < current->data){
        remove(current->left, value);
    } else if (value > current->data){
        remove(current->right, value);
    } else {
        delete current;
        current = nullptr;
    }
}
template <typename T> void binary_search_tree<T>::clear(node* &current) {
    if (current){
        clear(current->left);
        clear(current->right);
        delete current;
        current = nullptr;
    } else {
        return;
    }
}
template <typename T> bool binary_search_tree<T>::full(node* current) {
    if (current){
        bool left = full(current->left);
        bool right = full(current->right);
        if (current == root)
            return left and right;
        return not (left xor right);    // logic gates (left^right)
    } else {
        return false;
    }
}
template <typename T> bool binary_search_tree<T>::search(node* current, T value) {
    if (!current) {
        return false;
    } else if (value < current->data){
        return search(current->left, value);
    } else if (value > current->data){
        return search(current->right, value);
    }
    return true;
}
template <typename T> bool binary_search_tree<T>::balanced(node *current) {

}
template <typename T> std::string binary_search_tree<T>::inorder(node* current) {
    std::string inorder_str;
    if (current){
        inorder_str = inorder(current->left);
        inorder_str = inorder_str + std::to_string(current->data) + " ";
        inorder_str = inorder_str + inorder(current->right);
    } else {
        return "";
    }
    return inorder_str;
}
template <typename T> std::string binary_search_tree<T>::preorder(node* current) {
    std::string preorder_str;
    if (current){
        preorder_str = std::to_string(current->data) + " ";
        preorder_str = preorder_str + preorder(current->left);
        preorder_str = preorder_str + preorder(current->right);
    } else {
        return "";
    }
    return preorder_str;
}
template <typename T> std::string binary_search_tree<T>::postorder(node* current) {
    std::string postorder_str;
    if (current){
        postorder_str = postorder(current->left);
        postorder_str = postorder_str + postorder(current->right);
        postorder_str = postorder_str + std::to_string(current->data) + " ";
    } else {
        return "";
    }
    return postorder_str;
}
// improve and review f.size
template <typename T> size_t binary_search_tree<T>::size(node* current) {
    size_t count = 0;
    if (current){
        count = size(current->left);
        count = count + 1;
        count = count + size(current->right);
    } else {
        return 0;
    }
    return count;
}
template <typename T> size_t binary_search_tree<T>::height(node* current) {
    if (current){
        size_t left = height(current->left);
        size_t right = height(current->right);
        return std::max(left, right) + 1;
    } else {
        return 0;
    }
}
template <typename T> T binary_search_tree<T>::min_value(node* current) {
    if (!current){
        return T();
    } else if (!current->left){
        return current->data;
    } else {
        return min_value(current->left);
    }
}
template <typename T> T binary_search_tree<T>::max_value(node* current) {
    if (!current){
        return T();
    } else if (!current->right){
        return current->data;
    } else {
        return max_value(current->right);
    }
}
template <typename T> T binary_search_tree<T>::successor(node* current, T value) {
    if (!current) {
        return T();
    } else if (value < current->data) {
        T result = successor(current->left, value);
        return (result != T() ? result : current->data);
    } else {
        return successor(current->right, value);
    }
}
template <typename T> T binary_search_tree<T>::predecessor(node* current, T value) {
    if (!current){
        return T();
    } else if (value > current->data){
        T result = predecessor(current->right, value);
        return (result != T() ? result : current->data);
    } else {
        return predecessor(current->left, value);
    }
}

// methods
template <typename T> binary_search_tree<T>::binary_search_tree() {
    this->root = nullptr;
}
template <typename T> binary_search_tree<T>::~binary_search_tree() {
    this->clear();
}
template <typename T> void binary_search_tree<T>::insert(const T& value) {
    this->insert(root, value);
}
template <typename T> void binary_search_tree<T>::remove(const T& value) {
    this->remove(root, value);
}
template <typename T> void binary_search_tree<T>::clear() {
    this->clear(root);
}
template <typename T> bool binary_search_tree<T>::empty() {
    return root == nullptr;
}
template <typename T> bool binary_search_tree<T>::full() {
    if (!root || (!root->left && !root->right))
        return true;
    return full(root);
}
template <typename T> bool binary_search_tree<T>::search(T value) {
    this->search(root, value);
}
template <typename T> bool binary_search_tree<T>::balanced() {
    return true;
}
template <typename T> std::string binary_search_tree<T>::inorder() {
    return this->inorder(root);
}
template <typename T> std::string binary_search_tree<T>::preorder() {
    return this->preorder(root);
}
template <typename T> std::string binary_search_tree<T>::postorder() {
    return this->postorder(root);
}
template <typename T> std::string binary_search_tree<T>::BFS() {
    std::queue<node*> queue;
    std::string bfs;

    queue.push(root);
    while (!queue.empty()){
        bfs += std::to_string(queue.front()->data) + " ";
        if (queue.front()->left)
            queue.push(queue.front()->left);
        if (queue.front()->right)
            queue.push(queue.front()->right);
        queue.pop();
    }
    return bfs;
}
template <typename T> std::string binary_search_tree<T>::DFS() {
    std::stack<node*> stack;
    std::string dfs;

    stack.push(root);
    while (!stack.empty()){
        node* top = stack.top();
        stack.pop();
        dfs = std::to_string(top->data) + " " + dfs;
        if (top->left)
            stack.push(top->left);
        if (top->right)
            stack.push(top->right);
    }
    return dfs;
}
template <typename T> size_t binary_search_tree<T>::size() {
    return this->size(root);
}
template <typename T> size_t binary_search_tree<T>::height() {
    return this->height(root);
}
template <typename T> T binary_search_tree<T>::min_value() {
    return this->min_value(root);
}
template <typename T> T binary_search_tree<T>::max_value() {
    return this->max_value(root);
}
template <typename T> T binary_search_tree<T>::successor(T value) {
    return this->successor(root, value);
}
template <typename T> T binary_search_tree<T>::predecessor(T value) {
    return this->predecessor(root, value);
}

#endif //DATA_STRUCTURE_BINARY_TREE_H
