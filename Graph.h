#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

struct Vertex
{
  int shortestD = INT_MAX; //shortest distance from starting vertex
  Vertex* previousV = NULL; //vertex we just visited to get here
  int indexInMatrix = -1;
  char lable = ' ';
};

class Graph
{
  public:
  Graph();
  void addVertex(char newLable);
  void printAdjacencies();
  void addEdge(char startV, char endV, int weight);
  void removeVertex(char lable);
  void removeEdge(char startL, char endL);
  void shortestPath(char startL, char endL);
  Vertex* closestUnvisited(Vertex* unvisited[]);
  void resetVertexes();
  private:
  int graph[20][20];
  int index;
  Vertex* vertexes[20];
};

#endif