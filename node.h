#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std; 

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(){
        Node<T>* next = nullptr;
        Node<T>* prev = nullptr;
    }

    Node(T value){
        this->data = value;
        this->next = nullptr;
        this->prev= nullptr;
    }

    void killSelf(){
        this->next = nullptr;
        this->prev = nullptr;
    }
};

#endif



