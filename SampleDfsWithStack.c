#include <stdio.h>
#include "MyStack.h"//自作関数MyFuncStack.c を使用
#define nood 15
#define lim 3
int graph[nood][lim]={
	{1,2,3},
	{4,5,-1},
	{-1,-1,-1},
	{6,-1,-1},
	{7,8,9},
	{-1,-1,-1},
	{10,11,-1},
	{12,13,-1},
	{-1,-1,-1},
	{-1,-1,-1},
	{14,-1,-1},
	{-1,-1,-1},
	{-1,-1,-1},
	{-1,-1,-1},
	{-1,-1,-1}
};
int seen[nood]={0};
int stk[nood]={0};
d_stack s;
int path1[nood];
int count1=0;
void dfs(int start,int* seen){
	int seed;
	push(seed,&s);
	while(1)
	{
		if(pop(&seed,&s)==0){
			break;
		}
		seen[seed]=1;
		path1[count1]=seed;
		count1++;
		for(int i=0;i<lim;i++)
		{
			if(graph[seed][i]!=-1)
			{
				if(seen[graph[seed][i]]==0)
				{
					push(graph[seed][i],&s);
				}
			}
		}
	}
}
int main(){
	int seed=0;
	is(&s, stk,20);
	dfs(seed,seen);
	for(int i;i<nood;i++){
		printf("%d ",path1[i]);
	}
	printf("\n");
}
