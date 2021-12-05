#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define V 9
int minDistance(int dist[], bool sptSet[]) {
   int min = INT_MAX, min_index;
   for (int v = 0; v < V; v++)
   if (sptSet[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;
   return min_index;
}
int printSolution(int dist[], int n) {
   printf("Vertex Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t %d\n", i, dist[i]);
}
int * dijkstra(int graph[V][V], int src) {
   int * dist;
   dist=malloc(V*sizeof(int));
   bool sptSet[V];
   for (int i = 0; i < V; i++)
      dist[i] = INT_MAX, sptSet[i] = false;
      dist[src] = 0;
   for (int count = 0; count < V - 1; count++) {
      int u = minDistance(dist, sptSet);
      sptSet[u] = true;
      for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) dist[v] = dist[u] + graph[u][v];
   }
   return dist;
}
int main() {
   int graph[V][V] = { { 0, 6, 0, 0, 0, 0, 0, 8, 0 },
      { 6, 0, 8, 0, 0, 0, 0, 13, 0 },
      { 0, 8, 0, 7, 0, 6, 0, 0, 2 },
      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
      { 0, 0, 6, 14, 10, 0, 2, 0, 0 },
      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
      { 8, 13, 0, 0, 0, 0, 1, 0, 7 },
      { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
   };
   printSolution(dijkstra(graph, 0), V);
   return 0;
}