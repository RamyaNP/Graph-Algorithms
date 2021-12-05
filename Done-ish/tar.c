#include<stdio.h>
#include<stdlib.h>
//#include<stack>

//using namespace std;
typedef struct Stack{
	int top;
	int stack[500];
}Stack;

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
            findComponent(v, disc, low, stack, stkItem, graph);
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
                               
void strongConComponent(int ** graph) {
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
         findComponent(i, disc, low, &stack, stkItem, graph);
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
        printf("Edge%d :",i+1);
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=1;
       // graph[v2][v1]=1;
    }
    return graph;
}

int main() {
		int NODE, EDGE;
	printf("Number of vertices: ");
    scanf("%d",&NODE);
	printf("Number of edges:");
	scanf("%d", &EDGE);
	
	int ** graph;
	graph=read_graph_dir(NODE, EDGE);
    strongConComponent(graph);
}