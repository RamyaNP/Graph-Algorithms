#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
	int src, dest, weight;
}Edge;

typedef struct Graph
{
	int V, E;

	Edge* edge;
}Graph;

struct subset
{
	int parent;
	int rank;
};

int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);

void boruvkaMST(struct Graph* graph)
{
	int V = graph->V, E = graph->E;
	Edge *edge = graph->edge;

	struct subset subsets[V];

	int cheapest[V];

	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
		cheapest[v] = -1;
	}

	int numTrees = V;
	int MSTweight = 0;

	while (numTrees > 1)
	{
		for (int v = 0; v < V; ++v)
		{
			cheapest[v] = -1;
		}

		for (int i=0; i<E; i++)
		{
			int set1 = find(subsets, edge[i].src);
			int set2 = find(subsets, edge[i].dest);

			if (set1 == set2)
				continue;

			else
			{
			if (cheapest[set1] == -1 ||
				edge[cheapest[set1]].weight > edge[i].weight)
				cheapest[set1] = i;

			if (cheapest[set2] == -1 ||
				edge[cheapest[set2]].weight > edge[i].weight)
				cheapest[set2] = i;
			}
		}

		for (int i=0; i<V; i++)
		{
			if (cheapest[i] != -1)
			{
				int set1 = find(subsets, edge[cheapest[i]].src);
				int set2 = find(subsets, edge[cheapest[i]].dest);

				if (set1 == set2)
					continue;
				MSTweight += edge[cheapest[i]].weight;
				printf("Edge %d-%d included in MST\n",
					edge[cheapest[i]].src, edge[cheapest[i]].dest);

				Union(subsets, set1, set2);
				numTrees--;
			}
		}
	}

	printf("Weight of MST is %d\n", MSTweight);
	return;
}

struct Graph* createGraph(int V, int E)
{
	Edge * temp;
	temp=(Edge *)malloc(E*sizeof(Edge));
	Graph* graph;
	graph=(Graph *)malloc(sizeof(Graph));
	graph->V = V;
	graph->E = E;
	graph->edge = temp;
	return graph;
}

void makeGraph(int ** c_graph, int v, int e, Graph * graph){
	int k=0;
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			if (c_graph[i][j]>0){
				graph->edge[k].src = i;
				graph->edge[k].dest = j;
				graph->edge[k].weight = c_graph[i][j];
				k++;
			}
		}
	} 
}

int find(struct subset subsets[], int i)
{
	if (subsets[i].parent != i)
	subsets[i].parent =
			find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

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


int main()
{
void BMSTWrap(){
	int V, E;
	printf("Boruvka's MST");
	printf("V:");
	scanf("%d", &V);
	printf("E:");
	scanf("%d", &E);
	struct Graph* graph = createGraph(V, E);
	int ** p_graph;
	p_graph=read_graph_dir_wtd(V, E);
	makeGraph(p_graph, V, E, graph);boruvkaMST(graph);
}

	return 0;
}


