#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph()
{
  for(int i = 0; i < 20; i++) lables[i] = ' ';
  index = 0;
  for(int i = 0; i < 20; i++)
  {
    for(int j = 0; j < 20; j++)
    {
      graph[i][j] = false;    
    }
  }
}

void Graph::addVertex(char* lable)
{
  graph[index][index];
}

void Graph::printAdjacencies()
{
  cout << " " << endl;
  for(int i = 0; i < 20; i++) if(lables[i] != ' ') cout << lables[i] << "  "; 
  for(int i = 0; i < 20; i++) if(lables[i] != ' ') cout << lables[i] << " ;
}