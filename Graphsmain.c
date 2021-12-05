#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<conio.h>
#include"Graphs.h"

int main()
{
	int n;
	int e;
	printf("\n\t\t\t\t\t\t\t\tGraph Theory 2021\n\t\tAlgorithms in the order that they occur:\n");
	printf("\n\t\t\t1.) Welsh-Powell Graph Colouring");
	printf("\n\t\t\t2.) Fleury's Algorithm for printing Eulerian Path or Circuit");
	printf("\n\t\t\t3.) Maximum Bipartite Matching");
	printf("\n\t\t\t4.) Boruvka's algorithm for Minimum Spanning Trees");
	printf("\n\t\t\t5.) Reverse Delete Algorithm for Minimum Spanning Tree");
	printf("\n\t\t\t6.) Tarjan's Algorithm to find Strongly Connected Components");
	printf("\n\t\t\t7.) Solution to Chinese Postman Problem");
	printf("\n\n\nWelsh-Powell Graph Colouring\n\n");
    printf("Number of vertices: ");
    scanf("%d",&n);
	printf("\nNumber of edges:");
	scanf("%d", &e);
	//printf("success till here 1");
	int ** graph=read_graph(n,e);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tAdjecency Matrix\n");
	print_graph(graph,n);
	WelshPowell(n, e, graph);
	//copy_graph(n,e,graph);
	printf("\n\n\nFleury's Algorithm for printing Eulerian Path or Circuit\n");
	fleurys(n, e, graph);
	printf("\n\n\nMaximum Bipartite Matching\n");
	MaxMatchBipartite();
	printf("\n\n\nBoruvka's algorithm for Minimum Spanning Trees\n");
	BMSTWrap();
	printf("\n\n\nReverse Delete Algorithm for Minimum Spanning Tree\n");
	reverseDelete();
	printf("\n\n\nTarjan's Algorithm to find Strongly Connected Components\n");
	Tarjan();
	printf("\n\n\nSolution to Chinese Postman Problem\n");
	CPPWrp();
}	