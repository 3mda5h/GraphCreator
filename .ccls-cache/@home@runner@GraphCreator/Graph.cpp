#include "Graph.h"
#include <iostream>
#include <cstring>

using namespace std;

Graph::Graph()
{
  // -2 = node does not exist    -1 = node exists but no connection,
  for(int i = 0; i < 20; i++) for(int j = 0; j < 20; j++) graph[i][j] = -2;    
  for(int i = 0; i < 20; i++) lables[i] = ' ';
}

void Graph::addVertex()
{
  char newLable;
  cout << "vertex lable?" << endl;
  cin.get(newLable);
  cin.ignore();
  int index;
  for(int i = 0; i < 20; i++) 
  {
     if(lables[i] == ' ')
     {
       lables[i] = newLable;
       index = i;
       break;
     }
  }
  for(int i = 0; i < 20; i++) if(lables[i] != ' ') graph[i][index] = -1;
  for(int i = 0; i < 20; i++) if(lables[i] != ' ') graph[index][i] = -1;
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
  if(endV == startV) 
  {
    cout << "Bruh you can't make an edge like that" << endl; 
    cin.ignore();
    return;
  }
  cout << "Weight?" << endl;
  cin.ignore();
  cin.getline(weight, 10);
  int x = -1;
  int y = -1;
  for(int i = 0; i < 20; i++) if(lables[i] == startV) x = i;
  for(int i = 0; i < 20; i++) if(lables[i] == endV) y = i;
  if(x == -1 || y == -1) cout << "one of these verticies doesn't exist" << endl;
  else graph[x][y] = atoi(weight);
}

void Graph::removeVertex()
{
  char lable;
  cout << "Lable?" << endl;
  cin.get(lable);
  for(int i = 0; i < 20; i++) 
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
  for(int i = 0; i < 20; i++) for(int j = 0; j < 20; j++) 
    if(graph[i][j] == atoi(weight)) graph[i][j] = -1;
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
      if(graph[j][i] == -1) cout << "f   " ; 
      else if(graph[j][i] != -2) cout << graph[j][i] << "   " ;
    }
    cout << endl;
    cout << endl;
  }
}
