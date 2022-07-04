#ifndef LIST_H
#define LIST_H

#include "node.h"

// TODO: Implement all methods
template <typename T>
class List {
    private:
    int* head;
    int* tail;
    //Node<T> nodes;
    int nodes;
    public:
        List() : head(nullptr), tail(nullptr), nodes(0) {};
        virtual ~List(){
            // TODO
        };

        //Contrato
        virtual T front() = 0;
        virtual T back() = 0;
        virtual void push_front(T) = 0;
        virtual void push_back(T) = 0;
        virtual T pop_front() = 0;
        virtual T pop_back() = 0;
        virtual T insert(T, int) = 0;
        virtual T find(int) = 0;
        virtual bool remove(int) = 0;
        virtual T& operator[](int) = 0;//debe ser declarado en cada clase hija
        virtual bool is_empty() = 0;
        virtual int size() = 0;
        virtual void clear() = 0;
        virtual Node<T>* begin() = 0; 
        virtual Node<T>* end() = 0; 
        virtual Node<T>* aumentar(Node<T>*) = 0; 
};

#endif
