#include<stdio.h>
#include<conio.h>

int n;
int b[100],finalPath[100];
char ajMat[100][100];
int fp=0,count=0;
void displayPath();
int getDegree(int node);
int findRoot();
int getIndex(int node);
int isLastNode(int node);
int getNextNode(int node);
int isHasOneEdge(int node);
int isCompleted();
void removeEdge(int root,int eNode);
void printbArray();


//Display the Euler circuit/path
void displayPath()
{
     int i;
     for(i=0;i<fp;i++)
     {
       printf("%d ->",finalPath[i]);
     }
}

//To get the degree of node i.e no of edges currently connected to the node
int getDegree(int node)
{
    int j,deg=0;
    int pos=getIndex(node);
    for(j=0;j<n;j++)
    {
      if(ajMat[pos][j]=='y') deg++;
    }
    return deg;
}

//To assign the root of the graph
//Condition 1: If all Nodes have even degree, there should be a euler Circuit/Cycle
//We can start path from any node
//Condition 2: If exactly 2 nodes have odd degree, there should be euler path.
//We must start from node which has odd degree
//Condition 3: If more than 2 nodes or exactly one node have odd degree, euler path/circuit not possible.

//findRoot() will return 0 if euler path/circuit not possible
//otherwise it will return array index of any node as root
int findRoot()
{
    
     int i,cur=1;//Assume root as 1
     for(i=0;i<n;i++)
     {
        if(getDegree(b[i])%2!=0)
        {
           count++;
           cur=i;//Store the node which has odd degree to cur variable
        }
     }
     //If count is not exactly 2 then euler path/circuit not possible so return 0
     if(count!=0 && count!=2)
     {
        return 0;
     }
     else return b[cur];// if exactly 2 nodes have odd degree, it will return one of those node as root otherwise return 1 as root  as assumed
}

//To get the current index of node in the array b[] of nodes
int getIndex(int node)
{
    int k=0;
    while(node!=b[k])
    k++;
     //printf("inside while\n");
   
    //l++;
    return k;
}

int isLastNode(int node)
{
    int i=0;
    int degSum=0;
    for(i=0;i<n;i++)
    {
     degSum=degSum+getDegree(b[i]);
    }
    if(degSum==2)
      return 1;
    else
      return 0;
}

int getNextNode(int node)
{
    int i=0;
    int pos=getIndex(node);
        
    for(i=0;i<n;i++)
    {   
      if(ajMat[pos][i]=='y')
      {        
        if(!isHasOneEdge(b[i]))
        {
          return b[i];
        }
        else
        {
            if(isLastNode(b[i]))
            return b[i];
        }
      }
    }
    return -1;
}

int isHasOneEdge(int node)
{  
    if(getDegree(node)==1)
      return 1;
    else
      return 0;
}

int isCompleted()
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(getDegree(b[i])>0)
             return 0;
    }
    return 1;
}
void removeEdge(int root,int eNode)

{
     int pos1=0,pos2=0;    
     pos1=getIndex(root);
     pos2=getIndex(eNode);
     ajMat[pos1][pos2]='n';
     ajMat[pos2][pos1]='n';
}

//To find the Euler circuit/path and store it in finalPath[] array
void eularFind(int root)
{   
     int eNode;
     while(!isCompleted())
     {
        eNode=getNextNode(root);   //get Next node    
        finalPath[fp++]=eNode;     //add the node to euler path
        removeEdge(root,eNode);   //remove the edge
        root=eNode; //change the root
     }
    /* printf("root=%d\n",root);
        eNode=getNextNode(root);
        printf("getNextNode=%d \n",eNode);
        finalPath[fp++]=eNode;
        removeEdge(root,eNode);
        root=eNode;*/
}

void printbArray()
{
     int i;
      for( i=0; i<n; i++)
    {
     printf("%d  ",b[i]);//store the nodes in b[] array
    }
}
int main()
{
    char v;
    int i,j,l;
    printf("Enter the number of nodes in a graph\n");
    scanf("%d",&n);
    printf("Enter the value of node of graph\n");
    for( i=0; i<n; i++)
    {
     scanf("%d",&b[i]);//store the nodes in b[] array
    }
  
   
    //Get the Graph details by using adjacency matrix
    printf("Enter the value in adjancency matrix in form of 'Y' or 'N'\n");
    printf("\nIf there is an edge between the two vertices then enter 'Y' else 'N'\n");
    for( i=0; i<n; i++)
    printf(" %d ",b[i]);
    for( i=0;i<n; i++)
    {
     printf("\n%d ",b[i]);
     for( j=0; j<n; j++)
     {
      printf("%c ",v=getch());
      ajMat[i][j]=v;
     }
      printf("\n\n");
    }
  
/*   We can manually hard code the Graph value by below. But u need to command the above one to get the edge details.
ajMat[0][0]='n';
ajMat[0][1]='y';
ajMat[0][2]='n';
ajMat[0][3]='y';
ajMat[0][4]='n';
ajMat[0][5]='n';
           
ajMat[1][0]='y';
ajMat[1][1]='n';
ajMat[1][2]='y';
ajMat[1][3]='n';
ajMat[1][4]='y';
ajMat[1][5]='y';
           
ajMat[2][0]='n';
ajMat[2][1]='y';
ajMat[2][2]='n';
ajMat[2][3]='y';
ajMat[2][4]='y';
ajMat[2][5]='y';
           
ajMat[3][0]='y';
ajMat[3][1]='n';
ajMat[3][2]='y';
ajMat[3][3]='n';
ajMat[3][4]='n';
ajMat[3][5]='n';
           
ajMat[4][0]='n';
ajMat[4][1]='y';
ajMat[4][2]='y';
ajMat[4][3]='n';
ajMat[4][4]='n';
ajMat[4][5]='n';
           
ajMat[5][0]='n';
ajMat[5][1]='y';
ajMat[5][2]='y';
ajMat[5][3]='n';
ajMat[5][4]='n';
ajMat[5][5]='n';
 */ 
    //findRoot() will return 0 if euler path/circuit not possible
    //otherwise it will return array index of any node as root
    int root,pos;
    if(root=findRoot())
    {
      if(count) printf("Available Euler Path is\n");
      else printf("Available Euler Circuit is\n");
      finalPath[fp++]=root;
      eularFind(root);
      displayPath();
    }
    else printf("Euler path or circuit not available\n");
    getch();
}