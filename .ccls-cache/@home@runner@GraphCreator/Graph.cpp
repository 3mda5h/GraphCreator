#include "Graph.h"
#include <iostream>
#include <cstring>

using namespace std;

Graph::Graph()
{
  // -2 = node does not exist    -1 = node exists but no connection,  positive # = weight of connection
  for(int i = 0; i < 20; i++) for(int j = 0; j < 20; j++) graph[i][j] = -2; //graph[][]keeps track of connections   
  for(int i = 0; i < 20; i++) vertexes[i] = NULL; //vertexes[] keeps track of names of vertexes
}

//adds vertex (node) to adjacency matrix
void Graph::addVertex()
{
  char newLable;
  cout << "vertex lable?" << endl;
  cin.get(newLable);
  for(int i = 0; i < 20; i++) 
  {
    if(vertexes[i] && vertexes[i]->lable == newLable)
    {
      cout << "A vertex with that lable already exists!" << endl;
      cin.ignore();
      return;
    }
  }
  cin.ignore();
  int index;
  for(int i = 0; i < 20; i++) 
  {
     if(vertexes[i] == NULL) //insert in first empty spot
     {
       vertexes[i] = new Vertex;
       vertexes[i]->lable = newLable;
       vertexes[i]->indexInMatrix = i;
       index = i;
       break;
     }
  }
  for(int i = 0; i < 20; i++) if(vertexes[i] != NULL) graph[i][index] = -1;
  for(int i = 0; i < 20; i++) if(vertexes[i] != NULL) graph[index][i] = -1;
  cout << "Vertex added" << endl;
}

//adds edge (connection between to vertexes) 
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
    cout << "A node can't have an edge with itself! D:" << endl; 
    cin.ignore();
    return;
  }
  cout << "Weight?" << endl;
  cin.ignore();
  cin.getline(weight, 10);
  int x = -1;
  int y = -1;
  for(int i = 0; i < 20; i++) if(vertexes[i] && vertexes[i]->lable == startV) x = i;
  for(int i = 0; i < 20; i++) if(vertexes[i] && vertexes[i]->lable == endV) y = i;
  if(x == -1 || y == -1) cout << "one of those verticies doesn't exist" << endl;
  else 
  {
    graph[x][y] = atoi(weight);
    cout << "Edge added" << endl;
  }
}

void Graph::removeVertex()
{
  char lable;
  cout << "Lable?" << endl;
  cin.get(lable);
  for(int i = 0; i < 20; i++) 
  {
    if(vertexes[i] && vertexes[i]->lable == lable) 
    {
      delete vertexes[i];
      vertexes[i] = NULL;
      for(int j = 0; j < 20; j++) 
      {
        graph[i][j] = -2;
        graph[j][i] = -2;
      }
      cout << "Vertex removed" << endl;
      return;
    }
  }
  cout << "This vertex doesn't exist" << endl;
  cin.ignore();
}

void Graph::removeEdge()
{
  char weight[10];
  cout << "Weight?" << endl;
  cin.getline(weight, 10);
  for(int i = 0; i < 20; i++) for(int j = 0; j < 20; j++) 
    if(graph[i][j] == atoi(weight)) graph[i][j] = -1;
  cout << "Edge removed" << endl;
}

void Graph::shortestPath()
{
  char input;
  Vertex* startV = new Vertex();;
  Vertex* endV;
  Vertex* visited[20];
  for(int i = 0; i < 20; i++) visited[i] = NULL;
  Vertex* unvisited[20];
  for(int i = 0; i < 20; i++) unvisited[j] = vertexes[i]; 
  cout << "From vertex: " << endl;
  cin.get(input);
  for(int i = 0; i < 20; i++) if(vertexes[i]->lable == input) startV = vertexes[i];
  cout << "To vertex: " << endl;
  cin.get(input);
  for(int i = 0; i < 20; i++) if(vertexes[i]->lable == input) endV = vertexes[i];
  cin.ignore();


  //reset the stuff
  for(int i = 0; i < 20; i++)
  {
    vertexes[i]->shortestD = 1000000;
    vertexes[i]->previousV = NULL;
  }

}

void Graph::printAdjacencies()
{
  for(int i = 0; i < 20; i++) if(vertexes[i] != NULL) cout << "   " << vertexes[i]->lable; 
  cout << endl;
  for(int i = 0; i < 20; i++) 
  {
    if(vertexes[i] != NULL) cout << vertexes[i]->lable << "  ";
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
