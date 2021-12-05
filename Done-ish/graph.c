#include<stdio.h>
#include<stdlib.h>
//#include<limits.h>
//#include<conio.h>
//#include<string.h>
#define NODE 5
int graph[NODE][NODE] = {{0, 1, 1, 1, 1},
   {1, 0, 1, 1, 0},
   {1, 1, 0, 1, 0},
   {1, 1, 1, 0, 1},
   {1, 0, 0, 1, 0}
};
// {{0, 1, 1, 1, 1, 1}, 
	// {1, 0, 1, 1, 1, 1}, 
	// {1, 1, 0, 1, 1, 1}, 
	// {1, 1, 1, 0, 1, 1}, 
	// {1, 1, 1, 1, 0, 1}, 
	// {1, 1, 1, 1, 1, 0 },
   // };
int tempGraph[NODE][NODE];
static int edge;
int findStartVert(){
   for(int i = 0; i<NODE; i++){
      int deg = 0;
      for(int j = 0; j<NODE; j++){
         if(tempGraph[i][j])
         deg++; //increase degree, when connected edge found
      }
      if(deg % 2 != 0) //when degree of vertices are odd
      return i; //i is node with odd degree
   }
   return 0; //when all vertices have even degree, start from 0
}

int iseulerthere(){
	int count=0;
	for(int i = 0; i<NODE; i++){
      int deg = 0;
      for(int j = 0; j<NODE; j++){
         if(tempGraph[i][j])
         deg++; //increase degree, when connected edge found
      }
      if(deg % 2 != 0) //when degree of vertices are odd
       count++; //i is node with odd degree
   }
   if (count>2){
	   printf("No euler's circuit or trail");  
	   return 0;
   }
   else if (count==2)
	   return 1;
   else if (count==0)
	   return 2;
  
}

int edgeCount(){
   int count = 0;
   for(int i = 0; i<NODE; i++)
      for(int j = i; j<NODE; j++)
         if(tempGraph[i][j])
            count++;
   return count; //count nunber of edges in the graph
}

int isBridge(int u, int v){
   int deg = 0;
   for(int i = 0; i<NODE; i++)
      if(tempGraph[v][i])
         deg++;
      if(deg>1){
         return 0; //the edge is not forming bridge
      }
   return 1; //edge forming a bridge
}

void fleuryAlgorithm(int start){
	
   edge = edgeCount();
   for(int v = 0; v<NODE; v++){
      if(tempGraph[start][v]){ //when (u,v) edge is presnt and not forming bridge
         if(edge <= 1 || !isBridge(start, v)){
            printf("%d -- %d ", start, v);
            tempGraph[start][v] = tempGraph[v][start] = 0; //remove edge from graph
            edge--; //reduce edge
            fleuryAlgorithm(v);
         }
      }
   }
}

void fleurys(){
	int isethere= iseulerthere();
	if (isethere==0) return ;
	if (isethere==1) printf("trail:");
	if (isethere==2) printf("Circuit:");
	fleuryAlgorithm(findStartVert());
}
int main(){

   for(int i = 0; i<NODE; i++) //copy main graph to tempGraph
   for(int j = 0; j<NODE; j++)
	   tempGraph[i][j] = graph[i][j];
   printf( "Euler Path Or Circuit: ");
   fleurys();
}
