#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
int ** read_graph_dir_wtd(int n, int e)
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
        int v1,v2, wt;
        printf("Edge%d :",i+1);
        scanf("%d %d",&v1,&v2);
		printf("Weight?");
		scanf("%d",&wt);
        graph[v1][v2]=wt;
		
    }
    return graph;
}

int minKey(int key[], bool mstSet[], int V)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

int printMST(int parent[], int **graph, int V)
{	int mincost=0;
	printf("Edge \tWeight\n");
	for (int i = 1; i < V; i++)
		{printf("%d - %d \t%d \n", parent[i], i, graph[parent[i]][i]);
		mincost+=graph[parent[i]][i];}
	printf("Weight of MST is %d\n", mincost);
}

void primMST(int ** graph, int V, int E)
{
	int parent[V];
	int key[V];
	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet, V);

		mstSet[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v] )
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, graph, V);
}

int main()
{
	/* Let us create the following graph
		2 3
	(0)--(1)--(2)
	| / \ |
	6| 8/ \5 |7
	| /	 \ |
	(3)-------(4)
			9		 */
			
	//int V=5;
	int ** graph;/*[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };*/
	int V;
	int E;
    printf("Number of vertices: ");
    scanf("%d",&V);
	printf("Number of edges:");
	scanf("%d", &E);					
	graph=read_graph_dir_wtd(V, E);
	primMST(graph, V, E);

	return 0;
}
