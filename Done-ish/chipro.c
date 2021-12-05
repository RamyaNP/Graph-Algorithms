#include<stdio.h>
#include<stdlib.h>

int dijkstra(int ** graph, int src, int dst, int v, int e){
	int * shortest;
	shortest=calloc(v,sizeof(int));
	int *selected;
	selected=calloc(v,sizeof(int));
	selected[src]=1;
	int inf=100000000, min_sel=inf;
	int ind;
	for(int i=0; i<v; i++){
		if (i==src)
			shortest[src] = 0;
		else{
			if(graph[src][i]==0){
			shortest[i] = inf;}
            else{
                shortest[i] = graph[src][i];
                if(shortest[i] < min_sel){
                    min_sel = shortest[i];
					ind = i;}
			}
		}
	
	}
	if(src==dst) return 0;
	selected[ind]=1;
	while(ind!=dst){
        for (int i=0; i<v; i++){ 
            if (!selected[i]){
                if(graph[ind][i]!=0){
                    if((graph[ind][i] + min_sel) < shortest[i]){
		shortest[i] = graph[ind][i] + min_sel;}}}}
					int temp_min = 1000000;

        
        for (int j=0; j<v; j++){
            if (!selected[j]){
                if(shortest[j] < temp_min){
                    temp_min = shortest[j];
					ind = j;}}}
        min_sel = temp_min;
				selected[ind]=1;}
    int shrtst=shortest[dst];
	free(shortest);
	free(selected);
    return shrtst;
}

int * get_odd(int ** graph, int v){
	int * degrees;
    degrees = calloc(v,sizeof(int));
    for(int i=0; i<v; i++){
        for (int j=0; j<v; j++){
                if(graph[i][j]!=0)
				degrees[i]+=1;}}
                
    int * odds = calloc(v,sizeof(int));
	for (int i=0; i<v; i++){ 
		odds[i]=degrees[i]%2;}
    //print('odds are:',odds)
	free(degrees);
return odds;}


int main(){
	return 0;
}	