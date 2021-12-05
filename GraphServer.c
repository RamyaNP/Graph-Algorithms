#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<conio.h>
#include"Graphs.h"

int ** copy_graph(int n, int e, int ** graph)
{
	int ** c_graph;
    c_graph=malloc(n*sizeof(int*));
	    for(int i=0;i<n;i++)
    {
        c_graph[i]=calloc(n,sizeof(int));
    }
	for(int i = 0; i<n; i++) //copy main graph to tempGraph
		for(int j = 0; j<n; j++)
		c_graph[i][j] = graph[i][j];
  return c_graph;
}

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
        printf("\nEdge%d :",i+1);
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    return graph;
}

int ** read_graph_dir(int n, int e)
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
        printf("\nEdge%d :",i+1);
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=1;
       // graph[v2][v1]=1;
    }
    return graph;
}

int * Sort(int **  graph, int n) 
{ 
    int i, j;
    int*  arr=calloc(n,sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
            if(graph[i][j]==1)
                {arr[i]++;arr[j]++;}
    }
    int * desc=malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        int max=INT_MIN;
        int idx;
        for(j=0;j<n;j++)
            if(arr[j]>max)
            {
                max=arr[j];
                idx=j;
            }
        desc[i]=idx;
        arr[idx]=INT_MIN;
    }
    return desc;
}

void print_graph(int ** graph,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {	printf("\t");
        for(j=0;j<n;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
} 

void WelshPowell(int n, int e, int ** graph)
{	
	int i,j;
    int * desc=Sort(graph,n);
    //for(i=0;i<n;i++)
        //printf("%d ",desc[i]);
    int col=1;//first color is 1
    int * colored=calloc(n,sizeof(int));//0 means uncolored,else the value is color value
    int flag;//uncolored vertices exist
    while(1)
    {
        flag=1;
        //see if any uncolored edges exist &
        //find first uncolored vertex
        int uncolored_vertex;
        int uv;
        for(i=0;i<n;i++)
        {
            if(colored[desc[i]]==0)
            {
                flag=0;
                uncolored_vertex=desc[i];
                uv=i;
                break;
            }
        }
        //no uncolored vertex
        if(flag==1)
            break;
        //uncolored vertex exists
        else
        {
            //color with current color
            colored[uncolored_vertex]=col;
            //store all vertices with current color
            int * temp=malloc(sizeof(n)*n-1);
            int t=0;
            temp[t++]=uncolored_vertex;
            for(i=uv;i<n;i++)
            {
                if(colored[desc[i]]==0)
                {
                    int f=1;//not adjacent
                    //checking if its adjacent to any current color vertex
                    for(j=0;j<t;j++)
                    {
                        if(graph[i][temp[j]]==1)
                            f=0;
                    }
                    if(f)
                    {
                        colored[i]=col;
                        temp[t++]=i;
                    }
                }
            }
        }
        col++;

    }
    printf("The vertices are colored in the following pattern:\n");
    for(i=0;i<n;i++)
        printf("Vertex %d Color %d \n",i,colored[i]);
    printf("Chormatic number is : %d\n",col-1);
}

int findStartVert(int n, int ** graph){
   for(int i = 0; i<n; i++){
      int deg = 0;
      for(int j = 0; j<n; j++){
         if(graph[i][j])
         deg++; //increase degree, when connected edge found
      }
      if(deg % 2 != 0) //when degree of vertices are odd
      return i; //i is node with odd degree
   }
   return 0; //when all vertices have even degree, start from 0
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
	   printf("No euler's circuit or trail");  
	   return 0;
   }
   else if (count==2)
	   return 1;
   else if (count==0)
	   return 2;
  
}

int isBridge(int u, int v, int n, int ** graph){
   int deg = 0;
   for(int i = 0; i<n; i++)
      if(graph[v][i])
         deg++;
      if(deg>1){
         return 0; //the edge is not forming bridge
      }
   return 1; //edge forming a bridge
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


int edgeCount(int n, int ** graph){
   int count = 0;
   for(int i = 0; i<n; i++)
      for(int j = i; j<n; j++)
         if(graph[i][j])
            count++;
   return count; //count nunber of edges in the graph
}

void fleuryAlgorithm(int start, int n, int ** c_graph){

   int edge = edgeCount(n, c_graph);
   for(int v = 0; v<n; v++){
      if(c_graph[start][v]){ //when (u,v) edge is presnt and not forming bridge
         if(edge <= 1 || !isBridge(start, v, n, c_graph)){
            printf("%d -- %d ", start, v);
            c_graph[start][v] = c_graph[v][start] = 0; //remove edge from graph
            edge--; //reduce edge
            fleuryAlgorithm(v, n, c_graph);
         }
      }
   }
}

void fleurys(int n, int e, int ** graph){
	
	int isethere= iseulerthere(n, graph);
	printf( "Euler Path Or Circuit:\n\t");
	if (isethere==0){printf("Both aren't there"); return ;}
	if (isethere==1) printf("trail:\n\t\t");
	if (isethere==2) printf("Circuit:\n\t\t");
	int ** c_graph= copy_graph(n, e, graph);
	fleuryAlgorithm(findStartVert(n,graph),n,c_graph);
}

int bpm(int ** graph, int n, int u,int seen[], int matchR[])
{
	for (int v = 0; v < n; v++)
	{
		if (graph[u][v] && !seen[v])
		{
			seen[v] = TRUE;

			if (matchR[v] < 0 || bpm(graph, n, matchR[v],
									seen, matchR))
			{
				matchR[v] = u;
				return TRUE;
			}
		}
	}
	return FALSE;
}


int maxBPM(int ** graph, int n)
{
	int matchR[n];

	memset(matchR, -1, sizeof(matchR));

	int result = 0;
	for (int u = 0; u < n; u++)
	{
		int seen[n];
		memset(seen, 0, sizeof(seen));

		if (bpm(graph,n, u, seen, matchR))
			result++;
	}
	return result;
}

void MaxMatchBipartite(){
	int n;
	int e;
	printf("\nFor Maximum Bipartite Matching:\n\t");
    printf("Number of vertices: ");
    scanf("%d",&n);
	printf("\tNumber of edges:");
	scanf("%d", &e);
	int ** mmb_graph=read_graph_dir(n,e);
	printf("Maximum number of Matchings is ");
	printf("%d\n",maxBPM(mmb_graph,n));
}

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

int ** read_graph_wtd(int n, int e)
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
        printf("\nEdge%d :",i+1);
        scanf("%d %d",&v1,&v2);
		printf("\nWeight?");
		scanf("%d",&wt);
        graph[v1][v2]=wt;
		graph[v2][v1]=wt;
		
    }
    return graph;
}

void BMSTWrap(){
	int V, E;
	printf("Boruvka's MST\n");
	printf("\tV:");
	scanf("%d", &V);
	printf("\n\tE:");
	scanf("%d", &E);
	struct Graph* graph = createGraph(V, E);
	int ** p_graph;
	p_graph=read_graph_dir_wtd(V, E);
	makeGraph(p_graph, V, E, graph);
	boruvkaMST(graph);
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

void revdelMST(int ** graph, int V, int E)
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

void reverseDelete(){
			
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
	struct Graph* p_graph = createGraph(V, E);
	makeGraph(graph, V, E, p_graph);
	boruvkaMST(p_graph);
}


void push(Stack * stack, int inp){
	stack->top++;
	stack->stack[stack->top]=inp;
		
}
int pop(Stack * stack){
	int temp=stack->stack[stack->top];
	stack->stack[stack->top]=-130;
	stack->top--;
	return temp;
}

int top(Stack * stack){
	return stack->stack[stack->top];
}                        

                               
int min(int a, int b) {
   return (a<b)?a:b;
}
                               
void findComponent(int u, int disc[], int low[], Stack * stack, int stkItem[], int ** graph, int NODE) {
   static int time = 0;
   disc[u] = low[u] = ++time;    //inilially discovery time and low value is 1
   push(stack, u);
   stkItem[u] = 1;    //flag as u in the stack
   
   for(int v = 0; v<NODE; v++) {
      if(graph[u][v]) {
         if(disc[v] == -1) {   //when v is not visited
            findComponent(v, disc, low, stack, stkItem, graph, NODE);
            low[u] = min(low[u], low[v]);
         } else if(stkItem[v])    //when v is in the stack, update low for u
            low[u] = min(low[u], disc[v]);
      }
   }
   
   int poppedItem = 0;
   if(low[u] == disc[u]) {
      while(stack->stack[stack->top]!= u) {
         poppedItem = stack->stack[stack->top];
         printf("%d, ",poppedItem);
         stkItem[poppedItem] = 0;    //mark as item is popped
         pop(stack);
      }
      poppedItem =stack->stack[stack->top];
      printf("%d\n",poppedItem);
      stkItem[poppedItem] = 0;
      pop(stack);
   }
}
                               
void strongConComponent(int ** graph, int NODE) {
   int disc[NODE], low[NODE];
   int stkItem[NODE];
   Stack stack;
   stack.top=-1;
   //printf("%d", stack.top);
   //stack->stack
   for(int i = 0; i<NODE; i++) {    //initialize all elements
      disc[i] = low[i] = -1;
      stkItem[i] = 0;
   }
   
   for(int i = 0; i<NODE; i++)    //initialize all elements
      if(disc[i] == -1)
         findComponent(i, disc, low, &stack, stkItem, graph, NODE);
}

void Tarjan(){
	int NODE, EDGE;
	printf("Number of vertices: ");
    scanf("%d",&NODE);
	printf("Number of edges:");
	scanf("%d", &EDGE);
	
	int ** graph;
	graph=read_graph_dir(NODE, EDGE);
    strongConComponent(graph, NODE);
}

int minDistance(int dist[], bool sptSet[], int V) {
   int min = INT_MAX, min_index;
   for (int i = 0; i < V; i++)
   if (sptSet[i] == false && dist[i] <= min)
      min = dist[i], min_index = i;
   return min_index;
}


void CPPWrp(){
	int ** graph;
   int node, E;
   printf("\tV:");
   scanf("%d", &node );
   printf("\n\tE:");
   scanf("%d", &E);
   graph=read_graph_wtd(node,E);
   int fin;
   fin=ChinesePostman(graph, node);
   printf("\n\nMiniumn Cost Incurred: %d", fin);
}
