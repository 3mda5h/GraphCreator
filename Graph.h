#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

class Graph
{
  public:
  Graph();
  void addVertex();
  void printAdjacencies();
  void addEdge();
  void removeVertex();
  void removeEdge();
  private:
  int graph[20][20];
  int index;
  char lables[20];
};

#endif