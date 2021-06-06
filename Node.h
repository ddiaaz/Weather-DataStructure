#ifndef WEATHERPROJECT_NODE_H
#define WEATHERPROJECT_NODE_H

#include <iostream>

template <class T>
struct Node {
    int key;
    T data;
    Node<T> * next;

    Node();
    Node(T data, Node * next, int key);
};

template <class T>
Node<T>::Node() {
    this->data = T();
    this->next = 0;
}

template <class T>
Node<T>::Node(T data, Node * next, int key) {
    this->data = data;
    this->next = next;
    this->key = key;
}

template <class T>
std::ostream &operator<<(std::ostream &out, Node<T> *&node) {
    out << ' ' << node->data << ' ';
    return out;
}
#endif
