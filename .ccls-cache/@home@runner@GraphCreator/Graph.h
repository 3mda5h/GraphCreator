#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

struct Vertex
{
  int shortestD = 1000000; //shortest distance from starting vertex
  Vertex* previousV = NULL; //vertex we just visited to get here
  int indexInMatrix = -1;
  char lable = ' ';
  
};

class Graph
{
  public:
  Graph();
  void addVertex();
  void printAdjacencies();
  void addEdge();
  void removeVertex();
  void removeEdge();
  void shortestPath();
  private:
  int graph[20][20];
  int index;
  Vertex* vertexes[20];
};

#endif