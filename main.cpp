/*Graph Creator - user can add and delete vertexes from a graph. Edges between vertexes are
kept track of using an adjacency matrix. Dikjrsrta's algorithm can be used to find the shortest
path and distance between two vertexes 
Emily MacPherson
6/13/22
*/

#include <iostream>
#include <cstring>
#include "Graph.h"

using namespace std;

int main() 
{
  Graph* graph = new Graph();
  char input[10];
  while(strcmp(input, "quit") != 0)
  {
    cout << "Enter AV (add vertex), AE (add edge), RV (remove vertex), RE (remove edge), SP (shortest path), or PRINT" << endl;
    cin.getline(input, 10);
    for(int i = 0;i < strlen(input); i++) input[i] = tolower(input[i]);
    if(strcmp(input, "av") == 0) 
    {
      char newLable;
      cout << "vertex lable?" << endl;
      cin.get(newLable);
      graph->addVertex(newLable);
      cin.ignore();
    }
    else if(strcmp(input, "print") == 0) graph->printAdjacencies();
    else if(strcmp(input, "ae") == 0) 
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
        break;
      }
      cout << "Weight?" << endl;
      cin.ignore();
      cin.getline(weight, 10);
      int w = atoi(weight);
      graph->addEdge(startV, endV, w);
    }
    else if(strcmp(input, "rv") == 0) 
    {
      char lable;
      cout << "Lable?" << endl;
      cin.get(lable);
      graph->removeVertex(lable); 
      cin.ignore();
    }
    else if(strcmp(input, "re") == 0) 
    {
      char startL;
      char endL;
      cout << "From vertex?" << endl;
      cin.get(startL);
      cout << "To vertex?" << endl;
      cin.ignore();
      cin.get(endL);
      graph->removeEdge(startL, endL);
      cin.ignore();
    }
    else if(strcmp(input, "sp") == 0) 
    {
      char startL;
      char endL;
      cout << "From vertex: " << endl;
      cin.get(startL);
      cout << "To vertex: " << endl;
      cin.ignore();
      cin.get(endL);
      graph->shortestPath(startL, endL);
      cin.ignore();
    }
     //for testing 
    else if(strcmp(input, "test") == 0)
    {
      /*
      char l = 'A';
      graph->addVertex(l);
      l = 'B';
      graph->addVertex(l);
      l = 'C';
      graph->addVertex(l);
      l = 'D';
      graph->addVertex(l);
      char s = 'A';
      char e = 'B';
      int w = 7;
      graph->addEdge(s, e, w);
      e = 'C';
      w = 1;
      graph->addEdge(s, e, w);
      s = 'B';
      e = 'D';
      w = 8;
      graph->addEdge(s, e, w);
      s = 'C';
      e = 'D';
      w = 2;
      graph->addEdge(s, e, w);
      s = 'A';
      e = 'D';
      graph->shortestPath(s, e);
      */

      char l = 'A';
      graph->addVertex(l);
      l = 'B';
      graph->addVertex(l);
      l = 'C';
      graph->addVertex(l);
      l = 'D';
      graph->addVertex(l);
      l = 'E';
      graph->addVertex(l);
      l = 'F';
      graph->addVertex(l);
      int w = 7;
      char s = 'A';
      char e = 'B';
      graph->addEdge(s, e, w);
      e = 'C';
      w = 8;
      graph->addEdge(s, e, w);
      e = 'D';
      w = 1;
      graph->addEdge(s, e, w);
      s = 'B';
      e = 'E';
      w = 3;
      graph->addEdge(s, e, w);
      s = 'C';
      e = 'F';
      w = 1;
      graph->addEdge(s, e, w);
      s = 'D';
      w = 15;
      graph->addEdge(s, e, w);
      s = 'E';
      w = 3;
      graph->addEdge(s, e, w);
    }
  }
}