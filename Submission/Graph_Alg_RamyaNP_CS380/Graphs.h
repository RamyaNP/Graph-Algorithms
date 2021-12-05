#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<conio.h>
#include<string.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

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

typedef struct Stack{
	int top;
	int stack[500];
}Stack;

int ** read_graph(int n, int e);
int * Sort(int **  graph, int n);
void print_graph(int ** graph,int n);
void WelshPowell(int n, int e, int ** graph);
int findStartVert(int n, int ** graph);
int iseulerthere(int n, int ** graph);
int isBridge(int u, int v, int n, int ** graph);
int edgeCount(int n, int ** graph);
void fleuryAlgorithm(int start, int n, int ** graph);
void fleurys(int n, int e, int ** graph);
int ** copy_graph(int n, int e, int ** graph);
void MaxMatchBipartite();
int maxBPM(int ** graph, int n);
int bpm(int ** graph, int n, int u,int seen[], int matchR[]);
int ** read_graph_dir(int n, int e);
int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);
void boruvkaMST(struct Graph* graph);
struct Graph* createGraph(int V, int E);
void makeGraph(int ** c_graph, int v, int e, Graph * graph);
int ** read_graph_dir_wtd(int n, int e);
int ** read_graph_wtd(int n, int e);
void BMSTWrap();
int minKey(int key[], bool mstSet[], int V);
int printMST(int parent[], int **graph, int V);
void revdelMST(int ** graph, int V, int E);
void reverseDelete();
void push(Stack * stack, int inp);
int pop(Stack * stack);
int top(Stack * stack);
int min(int a, int b);
void findComponent(int u, int disc[], int low[], Stack * stack, int stkItem[], int ** graph, int NODE);
void strongConComponent(int ** graph, int NODE);
void Tarjan();
int minDistance(int dist[], bool sptSet[], int V);
int dijkstra(int ** graph, int src, int dest, int V);
int * odds(int v, int ** graph);
int countfun(int n, int ** graph);
int ChinesePostman(int ** graph, int v);
void CPPWrp();
