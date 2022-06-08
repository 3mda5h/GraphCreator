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
      graph[i][j] = -2;    
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
  for(int i = 0; i < 20; i++) if(lables[i] == ' ') lables[i] = newLable;
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
  for(int i = 0; i < 20; i++) if(lables[i] == startV) x = i;
  for(int i = 0; i < 20; i++) if(lables[i] == endV) y = i;
  //cout << "x: " << x << endl;
 // cout << "y: " << y << endl;
  //cout << "w: " << weight << endl;
  if(x == -1 || y == -1) cout << "one of these verticies doesn't exist" << endl;
  else graph[x][y] = atoi(weight);
}

void Graph::removeVertex()
{
  char lable;
  cout << "Lable?" << endl;
  cin.get(lable);
  for(int i = 0; i < index; i++) 
  {
    if(lables[i] == lable) 
    {
      lables[i] = ' ';
      for(int j = 0; j < 20; j++) 
      {
        graph[i][j] = -2;
        graph[j][i] = -2;
      }
    }
  }
}

void Graph::removeEdge()
{
  char weight[10];
  cout << "Weight?" << endl;
  cin.getline(weight, 10);
  for(int i = 0; i < index; i++) if(lables[i] == startV) x = i;
  for(int i = 0; i < index; i++) if(lables[i] == endV) y = i;
}

void Graph::printAdjacencies()
{
  for(int i = 0; i < 20; i++) if(lables[i] != ' ') cout << "   " << lables[i]; 
  cout << endl;
  for(int i = 0; i < 20; i++) 
  {
    if(lables[i] != ' ') cout << lables[i] << "  ";
    else continue;
    for(int j = 0; j < 20; j++)
    {
      if(graph[j][i] == -1) cout << "f   " ; //-1 = node exists but no connection, -2 = node does not exist
      else if(graph[j][i] != -2) cout << graph[j][i] << "   " ;
    }
    cout << endl;
    cout << endl;
  }
}
