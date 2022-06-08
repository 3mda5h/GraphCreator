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
      graph[i][j] = -1;    
    }
  }
  for(int i = 0; i < 20; i++) lables[i] = ' ';
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
  cin.ignore();
  cin.get(endV);
  cout << "Weight?" << endl;
  cin.ignore();
  cin.getline(weight, 10);
  int x = -1;
  int y = -1;
  for(int i = 0; i < index; i++) if(lables[i] == startV) x = i;
  for(int i = 0; i < index; i++) if(lables[i] == endV) y = i;
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "w: " << weight << endl;
  if(x == -1 || y == -1) cout << "one of these verticies doesn't exist" << endl;
  else graph[x][y] = atoi(weight);
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
      if(graph[j][i] == -1) cout << "f   " ; 
      else cout << graph[j][i] << "   " ;
    }
    cout << endl;
    cout << endl;
  }
}