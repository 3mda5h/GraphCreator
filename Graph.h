#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

class Graph
{
  public:
  Graph();
  void addVertex(char* lable);
  void printAdjacencies();
  private:
  bool graph[20][20];
  int index;
  char lables[];
};

#endif