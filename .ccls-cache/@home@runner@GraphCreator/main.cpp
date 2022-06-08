#include <iostream>
#include <cstring>
#include "Graph.h"

using namespace std;

int main() 
{
  Graph* graph = new Graph();
  char input[10];
  /* char c;
  char c2;
  cin.get(c);
  cin.ignore();
  cin.get(c2);
  cout << c << endl;
  cout << c2 << endl;
  if(c == c2) cout << "same" << endl;
  */
  while(strcmp(input, "quit") != 0)
  {
    cout << "enter AV (add vertex), AE (add edge) PRINT" << endl;
    cin.getline(input, 10);
    for(int i = 0;i < strlen(input); i++) input[i] = tolower(input[i]);
    if(strcmp(input, "av") == 0) graph->addVertex();
    else if(strcmp(input, "print") == 0) graph->printAdjacencies();
    else if(strcmp(input, "ae") == 0) graph->addEdge();
  }
}