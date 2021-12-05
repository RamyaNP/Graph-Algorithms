#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<conio.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
int n=6;
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

int main()
{
	int n=6;
	int ** graph;
	graph=malloc(n*sizeof(int*));
    int i,j;
    for(i=0;i<n;i++)
    {
        graph[i]=calloc(n,sizeof(int));
    }
	int e;
	printf("e: ");
	scanf("%d", &e);
    //printf("\nEnter vertex pairs with edge in between : Eg. (0 1) -> Edge between V0 and V1\n");
	    printf("\nEnter vertex pairs with edge in between : Eg. (0 1) -> Edge between V0 and V1\n");
    for(i=0;i<e;i++)
    {
        int v1,v2;
        printf("Edge%d :",i+1);
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
	printf("Maximum number of applicants that can get job is ");
	printf("%d\n",maxBPM(graph,n));

	return 0;
}
