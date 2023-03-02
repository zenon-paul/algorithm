#include <stdio.h>
#define NODE 10
#define ELIM 15
#define BLIM 5
int edge[ELIM][3] = {
	{1,2},
	{1,4},
	{2,5},
	{2,3},
	{3,5},
	{4,6},
	{5,6},
	{0,1},
	{0,2},
	{0,3}
};
int flag = 0;
int graph[NODE][BLIM];
int e = 0;
int n = 0;
int start = 0;
int goal = 6;
int seen [NODE];
int path[NODE];
int depth = 0;
void init_graph(){
	for(int i = 0;i<NODE;i++)
	{
		for(int j = 0;j < BLIM;j++)
		{
			graph[i][j] = -1;
		}
	}
	for(int i = 0;i < e;i++)
	{
		int j = 0;
		while(graph[edge[i][0]][j] != -1)
		{
			j++;
		}
		graph[edge[i][0]][j] = edge[i][1];
		int k = 0;
		while(graph[edge[i][1]][k] != -1)
		{
			k++;
		}
		graph[edge[i][1]][k] = edge[i][0];
	}
}
void dfs(int* seen,int seed,int count){
	printf("(%d)\n",seed);
	seen[seed] = 1;
	if(seed == goal)
	{
		flag = 1;
		return;
	}
	if(count >= depth)
	{
		return;
	}
	int i = 0;
	while(graph[seed][i] != -1)
	{
		if(seen[graph[seed][i]] == 0){
			dfs(seen,graph[seed][i],count +1);
			path[graph[seed][i]] = seed;
		}
		i++;
	}
}
void get_path(){
	int current = goal;
	while(current != -1){
		printf("%d < ",current);
		current = path[current];
	}
}
int main(){
	e = 10;
	n = 7;
	init_graph();
	while(flag == 0)
	{
		for(int i = 0;i < NODE;i++)
		{
			path[i] = -1;
			seen[i] = 0;
		}
		printf("@%d\n",depth);
		dfs(seen,start,0);
		depth++;
	}
	get_path();
	printf("\n");
	for(int i = 0;i<NODE;i++)
	{
		printf("%d ",path[i]);
	}
}
