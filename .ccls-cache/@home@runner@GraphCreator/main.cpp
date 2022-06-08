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
    cout << "enter AV (add vertex), AE (add edge), RV (remove vertex), RE (remove edge), or PRINT" << endl;
    cin.getline(input, 10);
    for(int i = 0;i < strlen(input); i++) input[i] = tolower(input[i]);
    if(strcmp(input, "av") == 0) graph->addVertex();
    else if(strcmp(input, "print") == 0) graph->printAdjacencies();
    else if(strcmp(input, "ae") == 0) graph->addEdge();
    else if(strcmp(input, "rv") == 0) graph->removeVertex(); 
  }
}