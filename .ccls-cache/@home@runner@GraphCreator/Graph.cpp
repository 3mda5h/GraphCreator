#include "Graph.h"
#include <iostream>
#include <cstring>

using namespace std;

Graph::Graph()
{
  index = 0;
  for(int i = 0; i < 20; i++)
  {
    for(int j = 0; j < 20; j++)
    {
      graph[i][j] = 0;    
    }
  }
}

void Graph::addVertex()
{
  char newLable;
  cout << "vertex lable?" << endl;
  cin.get(newLable);
  cin.ignore();
  lables[index] = newLable;
  index++;
}

void Graph::addEdge()
{
  char startV;
  char endV;
  char weight[10];
  cout << "From vertex: " << endl;
  cin.get(startV);
  cout << "To vertex: " << endl;
  cin.get(endV);
  cin.ignore();
  cout << "Weight?" << endl;
  cin.ignore();
  cin.getline(weight, 10);
  int x;
  int y;
  for(int i = 0; i < 20; i++) if(lables[i] == startV) x = i;
  for(int i = 0; i < 20; i++) if(lables[i] == endV) y = i;
  graph[x][y] = atoi(weight);
}

void Graph::printAdjacencies()
{
  for(int i = 0; i < index; i++) cout << "   " << lables[i] ; 
  cout << endl;
  for(int i = 0; i < index; i++) 
  {
    cout << lables[i] << "  ";
    for(int j = 0; j < index; j++)
    {
      cout << graph[j][i] << "   " ; 
    }
    cout << endl;
    cout << endl;
  }
}