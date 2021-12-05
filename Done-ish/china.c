#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include <stdbool.h>


int ** read_graph(int n, int e)
{
    int ** graph;
    graph=malloc(n*sizeof(int*));
    int i,j;
    for(i=0;i<n;i++)
    {
        graph[i]=calloc(n,sizeof(int));
    }
    printf("\nEnter vertex pairs with edge in between : Eg. (0 1) -> Edge between V0 and V1\n");
    for(i=0;i<e;i++)
    {
        int v1,v2;
        printf("Edge%d :",i+1);
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    return graph;
}

int iseulerthere(int n, int ** graph){
	int count=0;
	for(int i = 0; i<n; i++){
      int deg = 0;
      for(int j = 0; j<n; j++){
         if(graph[i][j])
         deg++; //increase degree, when connected edge found
      }
      if(deg % 2 != 0) //when degree of vertices are odd
       count++; //i is node with odd degree
   }
   if (count>2){
	   //printf("No euler's circuit or trail");  
	   return 0;
   }
   else if (count==2)
	   return 1;
   else if (count==0)
	   return 2;
  
}

int minDistance(int dist[], bool sptSet[], int V) {
   int min = INT_MAX, min_index;
   for (int i = 0; i < V; i++)
   if (sptSet[i] == false && dist[i] <= min)
      min = dist[i], min_index = i;
   return min_index;
}

int dijkstra(int ** graph, int src, int dest, int V) {
   int * dist;
   int temp;
   dist=malloc(V*sizeof(int));
   bool sptSet[V];
   for (int i = 0; i < V; i++)
      dist[i] = INT_MAX, sptSet[i] = false;
      dist[src] = 0;
   for (int count = 0; count < V - 1; count++) {
      int u = minDistance(dist, sptSet, V);
      sptSet[u] = true;
      for (int j = 0; j < V; j++)
         if (!sptSet[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]) dist[j] = dist[u] + graph[u][j];
   }
   temp=dist[dest];
   free(dist);
   return temp;
}

int * odds(int v, int ** graph){
	int count=0;
	int odd[v];
	for(int i = 0; i<v ; i++){
      int deg = 0;
      for(int j = 0; j<v ; j++){
         if(graph[i][j])
         deg++; //increase degree, when connected edge found
      }
      if(deg % 2 != 0) //when degree of vertices are odd
      { count++;
		odd[i]=1;
	  
	  }
	  else odd[i]=0;//i is node with odd degree
   }
   int *odds;
   int k=0;
   odds=(int *)malloc(count*sizeof(int));
   for(int i=0; i<v; i++){
	   if(odd[i]==1)
			odds[k]=i;
   }
   return odds;
  
}
int countfun(int n, int ** graph){
	int count=0;
	for(int i = 0; i<n; i++){
      int deg = 0;
      for(int j = 0; j<n; j++){
         if(graph[i][j])
         deg++; //increase degree, when connected edge found
      }
      if(deg % 2 != 0) //when degree of vertices are odd
       count++; //i is node with odd degree
   }
   return count;
}

int ChinesePostman(int ** graph, int v){
	int sum=0;
		for(int i=0; i<v; i++){
			for(int j=0; j<v; j++){
				if (graph[i][j]!=0){
					sum+=graph[i][j];
				}
				
			}
		}
	if (iseulerthere(v,graph)!=0){
		
		return sum/2;
	}
	else {
		sum=sum/2;
		int count;
		int min1=100000;
		int min2=100000;
		count=countfun(v, graph);
		int * odd;
		odd=odds(v,graph);
		for (int i=0; i<count; i++){
			for (int j=0; j<count; j++ ){
				if (i!=j){
					int s=dijkstra(graph,i, j, v);
					if (min1>s){
					min2=min1;
					min1=s;
					}
					else if (min2>s){
						min2=s;
					}
				}
				
			}
		}
		
	sum+=min1+min2;
	return sum;
	}
}

int main(){
	// int graph[V][V] = {
		// {0, 1, 1, 1, 1},
		// {1, 0, 1, 0, 0},
		// {1, 1, 0, 0, 0},
		// {1, 0, 0, 0, 1},
		// {1, 0, 0, 1, 0}
   // };
   int ** graph;
   int node, E;
   printf("\tV:");
   scanf("%d", &node );
   printf("\n\tE:");
   scanf("%d", &E);
   graph=read_graph(node,E);
   int fin;
   fin=ChinesePostman(graph, node);
   printf("%d", fin);
   
	return 0;
}	