#include<iostream>
#include<vector>
#define NODE 4
using namespace std;
int graph[NODE][NODE] = {{0, 2, 2, 1},
   {2, 0, 0, 1},
   {2, 0, 0, 1},
   {1, 1, 1, 0},
   };
int tempGraph[NODE][NODE];
int findStartVert(){
   for(int i = 0; i<NODE; i++){
      int deg = 0;
      for(int j = 0; j<NODE; j++){
         if(tempGraph[i][j])
         deg+=tempGraph[i][j]; //increase degree, when connected edge found
      }
      if(deg % 2 != 0) //when degree of vertices are odd
      return i; //i is node with odd degree
   }
   return 0; //when all vertices have even degree, start from 0
}
bool isBridge(int u, int v){
   int deg = 0;
   for(int i = 0; i<NODE; i++)
      if(tempGraph[v][i])
         deg+=tempGraph[v][i];
      if(deg>1){
         return false; //the edge is not forming bridge
      }
   return true; //edge forming a bridge
}
int edgeCount(){
   int count = 0;
   for(int i = 0; i<NODE; i++)
      for(int j = i; j<NODE; j++)
         if(tempGraph[i][j])
            count++;
   return count; //count nunber of edges in the graph
}
void fleuryAlgorithm(int start){
   static int edge = edgeCount();
   for(int v = 0; v<NODE; v++){
      if(tempGraph[start][v]){ //when (u,v) edge is presnt and not forming bridge
         if(edge <= 1 || !isBridge(start, v)){
            cout << start << "--" << v << " ";
            tempGraph[start][v] = tempGraph[v][start] = 0; //remove edge from graph
            edge--; //reduce edge
            fleuryAlgorithm(v);
         }
      }
   }
}
int main(){
   for(int i = 0; i<NODE; i++) //copy main graph to tempGraph
   for(int j = 0; j<NODE; j++)
   tempGraph[i][j] = graph[i][j];
   cout << "Euler Path Or Circuit: ";
   fleuryAlgorithm(findStartVert());
}
