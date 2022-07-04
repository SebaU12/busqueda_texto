#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include "double.h"

using namespace std;

struct Vertex;

struct Edge;

struct Vertex {
    string data;
    int id;
    List<Edge*> *edges = new DoubleList<Edge*>();
    Vertex(){};
    Vertex(string _data, int _id): data(_data), id(_id){};
    ~Vertex(){};
};

struct Edge {
    Vertex *vertexes[2];
    char transition;
    int id;
    string data; 
    Edge(){};
    Edge(Vertex *vertex1, Vertex *vertex2, char _transition) {
      this->vertexes[0] = vertex1;
      this->vertexes[1] = vertex2;
      this->transition = _transition;
    };
    ~Edge(){};
};


#endif
