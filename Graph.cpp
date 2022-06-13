#include "Graph.h"
#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

Graph::Graph()
{
  // -2 = node does not exist    -1 = node exists but no connection,  positive # = weight of connection
  for(int i = 0; i < 20; i++) for(int j = 0; j < 20; j++) graph[i][j] = -2; //graph[][]keeps track of connections   
  for(int i = 0; i < 20; i++) vertexes[i] = NULL; //vertexes[] keeps track of the actual vertexes
}

//adds vertex (node) to adjacency matrix
void Graph::addVertex(char newLable)
{
  for(int i = 0; i < 20; i++) 
  {
    if(vertexes[i] && vertexes[i]->lable == newLable)
    {
      cout << "A vertex with that lable already exists!" << endl;
      cin.ignore();
      return;
    }
  }
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

//adds edge (connection between two vertexes with a certain distance/weight) 
void Graph::addEdge(char startV, char endV, int weight)
{
  cout << "weight: " << weight << endl;
  int x = -1;
  int y = -1;
  for(int i = 0; i < 20; i++) if(vertexes[i] && vertexes[i]->lable == startV) x = i;
  for(int i = 0; i < 20; i++) if(vertexes[i] && vertexes[i]->lable == endV) y = i;
  if(x == -1 || y == -1) cout << "one of those verticies doesn't exist" << endl;
  else 
  {
    graph[x][y] = weight;
    cout << "Edge added" << endl;
  }
}

//removes vertex and its edges from adjacency matrix
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

//removes edge with a given weight
void Graph::removeEdge()
{
  char weight[10];
  cout << "Weight?" << endl;
  cin.getline(weight, 10);
  for(int i = 0; i < 20; i++) for(int j = 0; j < 20; j++) 
    if(graph[i][j] == atoi(weight)) graph[i][j] = -1;
  cout << "Edge removed" << endl;
}

//uses Dikjrsrta's algormithm to find the shortest path and distance from given start vertex to given end vertex
void Graph::shortestPath(char startL, char endL)
{
  Vertex* startV;
  Vertex* endV;
  Vertex* unvisited[20];
  for(int i = 0; i < 20; i++) 
  {
    if(vertexes[i] != NULL) 
    {
      unvisited[i] = vertexes[i];
    } else unvisited[i] = NULL;
  }
  for(int i = 0; i < 20; i++) if(vertexes[i] && vertexes[i]->lable == startL) startV = vertexes[i];
  for(int i = 0; i < 20; i++) if(vertexes[i] && vertexes[i]->lable == endL) endV = vertexes[i];

  Vertex* current = startV;
  startV->shortestD = 0;
  int distance = 0; //distance of a neighbor vertex from current vertex
  while(current != NULL)
  {
    //get neighbors
    for(int i = 0; i < 20; i++)
    {
      if(graph[current->indexInMatrix][i] > -1)  //if there is a connection
      {
        //cout << "current is " << current->lable << " and we are visiting " << vertexes[i]->lable << endl;
        distance = graph[current->indexInMatrix][i]; 
        //cout << "distance of " << current->lable << " from " << vertexes[i]->lable << " is " << distance << endl;
        if(vertexes[i]->shortestD > distance + current->shortestD) //if we've found a shorter path from the start vertex to vertexes[i]
        {
          vertexes[i]->shortestD = distance + current->shortestD;
          vertexes[i]->previousV = current;
          //cout<< "shortest distance of " << vertexes[i]->lable << " is now " << vertexes[i]->shortestD << endl;
        }
      }
    }
    unvisited[current->indexInMatrix] = NULL; //remove current from unvisited list
    current = closestUnvisited(unvisited);
  }
  
  char path[20];
  for(int i = 0; i < 20; i++) path[i] = ' ';
  path[0] = startV->lable;
  cout << "The shortest path is: ";
  int i = 19;
  current = endV;
  while(current != startV) //backtrack from endV to startV through previous vertexes
  {
    path[i] = current->lable;
    current = current->previousV;
    i--;
  }
  for(int i = 0; i < 20; i++) if(path[i] != ' ') cout << path[i] << ", "; 
  cout << endl;
  cout << "With a total distance of: " << endV->shortestD << endl;
  cout << endl;
  
  //reset vertexes
  for(int i = 0; i < 20; i++)
  {
    if(vertexes[i])
    {
      vertexes[i]->shortestD = INT_MAX;
      vertexes[i]->previousV = NULL;
    }
  } 
}

//returns vertex in unvisited array that is closest to the starting vertex
Vertex* Graph::closestUnvisited(Vertex* unvisited[20])
{
  int smallestSoFar = INT_MAX;
  Vertex* closest = NULL;
  for(int i = 0; i < 20; i++) 
  {
    if(unvisited[i] && (unvisited[i]->shortestD < smallestSoFar))
    {
      closest = unvisited[i];
      smallestSoFar = unvisited[i]->shortestD;
    }
  }
  return closest;
}

//prints the adjacency matrix showing all edges between nodes and their weights
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
