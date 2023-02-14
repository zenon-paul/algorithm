#include <stdio.h>
#include <limits.h>
#include "lib_1.h"//lib_pr_queue.cを使用
#define NODE 10
#define ELIM 15
#define BLIM 5
#define INF INT_MAX/2
#define SIZE 60
int valbody[SIZE] = {0};
int indbody[SIZE] = {0};
int path[NODE] = {0};
int dist[NODE] = {0};
int edge[ELIM][3] = {
	{1,2,18},
	{1,4,4},
	{2,5,1},
	{3,2,3},
	{3,5,5},
	{4,6,21},
	{5,6,9},
	{0,1,10},
	{0,2,16},
	{0,3,12}
};
int graph[NODE][BLIM][2];
void init_path(int n){
	for(int i = 0;i < n;i++)
	{
		path[i] = -1;
	}
}
void init_dist(int n){
	for(int i = 0;i < n;i++)
	{
		dist[i] = INF;
	}
}
void init_graph(int e,int n){
	for(int i = 0;i < NODE;i++)
	{
		for(int j = 0;j < BLIM;j++)
		{
			graph[i][j][1] = -1;
		}
	}
	for(int i = 0;i < e;i++)
	{
		int j = 0;
		while(graph[edge[i][0]][j][1] != -1)
		{
			j++;
		}
		graph[edge[i][0]][j][0] = edge[i][1];
		graph[edge[i][0]][j][1] = edge[i][2];
	}
}
int dijkstr(d2_prqueue *x,int s,int g){
	int val= 0;
	int from = 0;
	p2_put(x,0,s);
	while(p2_get(x,&val,&from))
	{
		if(val > dist[from])
		{
			continue;
		}
		for(int i = 0;i < BLIM;i++)
		{
			int to = 0;
			int cost = graph[from][i][1];
			to = graph[from][i][0];
			if(graph[from][i][1] != -1)
			{
				if(val + cost < dist[to])
				{
					dist[to] = val + cost;
					p2_put(x,dist[to],to);
					path[to] = from;
				}
			}
		}
	}
	return dist[g];
}
int get_path(int s,int g){
	int count = 0;
	int current = g;
	while((current != s)&&(current != -1))
	{
		printf("%d< ",current);
		current = path[current];
		count++;
	}
	return count;
}
int main(){
	d2_prqueue property;
	int cost = 0;
	int start = 0;
	int goal = 6;
	int count = 0;
	int node = 7;
	int edge = 10;
	ip2(&property,valbody,indbody,SIZE);
	init_path(node);
	init_dist(node);
	init_graph(edge,node);
	dist[start] = 0;
	cost = dijkstr(&property,start,goal);
	printf("\n");
	for(int i = 0;i < node;i++)
	{
		printf("%d ",dist[i]);
	}
	printf("\n");
	for(int i = 0;i < node;i++)
	{
		int j = 0;
		while(graph[i][j][1] != -1)
		{
			printf("%d: %d ",graph[i][j][0],graph[i][j][1]);
			j++;
		}
		printf("\n");
	}
	printf("\n%d\n",cost);
	count = get_path(start,goal);
}
