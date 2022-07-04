#ifndef PVECTOR_H
#define PVECTOR_H

#include <iostream> 
using namespace std; 

class pvector{
  private: 
    int size_vec = 0; 
    char *vecord = nullptr;  
  public: 
    string data; 
    int id; 
    pvector(){this->size_vec = 0;};
    pvector(int size); 
    pvector(string input); 
    void display(); 
    int size(){return this->size_vec;} 
    char get_data(int pos); 
    ~pvector(){};
}; 

pvector::pvector(int size){
  this->size_vec = size; 
  char value; 
  char *Newvectord = new char[size];
  for (int i = 0; i < size; i++){
    cin >> Newvectord[i]; 
  }
  this->vecord = Newvectord; 
}

pvector::pvector(string input){
  this->size_vec = input.size(); 
  char value; 
  char *Newvectord = new char[this->size_vec];
  for (int i = 0; i < this->size_vec; i++){
    Newvectord[i] = input[i]; 
  }
  this->vecord = Newvectord; 
}


void pvector::display(){
  for (int i = 0; i < this->size_vec; i++){
    cout << this->vecord[i]; 
  }
}

char pvector::get_data(int pos){
  return this->vecord[pos]; 
}

#endif
