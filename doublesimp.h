#ifndef DOUBLESIMP_H
#define DOUBLESIMP_H
#include <iostream>
#include "list.h"

using namespace std;

// TODO: Implement all methods
template <typename T>
class DoubleSimp: public List<T> {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes = 0;
    public:
        DoubleSimp() : List<T>() {}

        ~DoubleSimp(){ 
         	// TODO            
        }
        T front(){
            return this->head->data;
        }

        T back(){
            return tail->data; 
        }

        void push_front(T data){
            Node<T>* newNode = new Node<T>(data);
            if(this->size()==0) {
                this->head = newNode; 
            } else {
                newNode->next = this->head; 
                this->head->prev = newNode; 
                this->head = newNode; 
            }
            this->nodes = this->nodes + 1; 
        }

        void push_back(T data){
            Node<T>* newNode = new Node<T>(data);
            if(this->size()==0) {
                this->head = newNode; 
                this->tail = newNode; 
            } else {
                newNode->prev = this->tail; 
                this->tail->next = newNode; 
                this->tail = newNode;
            }
            this->nodes = this->nodes + 1; 
        }
        T pop_front(){
            
            Node<T>* deleteNode = this->head; 
            T result = deleteNode->data; 
            if(this->nodes != 1){
              this->head = this->head->next; 
              delete this->head->prev; 
              this->head->prev = nullptr;
            } else {
              delete this->head; 
              this->head = nullptr; 
            }
            this->nodes = this->nodes - 1; 
            return result; 
        }

        T pop_back(){
            Node<T>* deleteNode = this->tail; 
            T result = deleteNode->data; 
            if(this->nodes > 1){
              this->tail = this->tail->prev; 
              delete this->tail->next; 
              this->tail->next = nullptr;
            } else {
              this->tail = nullptr; 
            }
            this->nodes = this->nodes - 1; 
            return result; 
        }

        T insert(T data, int pos){
            Node<T>* newNode = new Node<T>(data);
            int i = 0;
            Node<T>* tempNode1 = this->head;
            while (true){
                if(i + 2  == pos){
                    Node<T>* tempNode2 = tempNode1->next;
                    tempNode1->next = newNode; 
                    newNode->prev = tempNode1; 
                    newNode->next = tempNode2;
                    tempNode2->prev = newNode; 
                    break; 
                } else {
                    tempNode1 = tempNode1->next; 
                }
                i++; 
            } 
            this->nodes = this->nodes + 1; 
            return data; 
        }

        bool remove(int pos){
            throw ("sin definir");
        }

        T& operator[](int pos){
            Node<T>* tempNode = this->head; 
            int i = 0; 
            while (true){
                if(i + 1  == pos){
                    return tempNode->data; 
                    break; 
                } else {
                    tempNode = tempNode->next; 
                }
              i++; 
            }    
        }
        
        bool is_empty(){
            if(this->nodes == 0)return true;
            return false; 
        }

        int size(){
            return this->nodes;
        }
        void clear(){
          if(this->nodes > 0){
            Node<T>* tempNode = this->head;
            while(this->head != nullptr){
              if(this->nodes == 1){
                this->head == nullptr; 
                break;
              }
                if(this->head->next != nullptr){
                    tempNode = this->head->next; 
                }
                if(this->head->next != nullptr){
                    this->head->killSelf(); 
                    this->head = tempNode; 
                    if(this->head->next == nullptr){
                        this->head->killSelf(); 
                        this->head = nullptr; 
                    }
                }
                this->nodes--;
            }
            this->tail = nullptr; 
            this->nodes--;
          }    
          this->head = nullptr; 
          this->tail = nullptr; 
        }

        T find(int id){
          return this->head->data; 
        }

        Node<T>* begin(){
          return this->head; 
        }
        Node<T>* end(){
          return this->tail; 
        }

        Node<T>* aumentar(Node<T> *nodoAumentar){
          return nodoAumentar->next; 
        } 

};
#endif

