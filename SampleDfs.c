#include <stdio.h>
#define nood 13
#define lim 3
int graph[nood][lim]={
	{1,2,3},
	{4,5,-1},
	{6,7,8},
	{9,-1,-1},
	{10,-1,-1},
	{11,12,-1},
	{-1,-1,-1},
	{-1,-1,-1},
	{-1,-1,-1},
	{-1,-1,-1},
	{-1,-1,-1},
	{-1,-1,-1},
	{-1,-1,-1}
};
int path1[nood]={0};
int path2[nood]={0};
int count1=0;
int count2=0;
void dfs(int seen[nood],int seed){
	seen[seed]=1;
	path1[count1]=seed;
	count1++;
	for(int i=0;i<lim;i++){
       　　　　 if(graph[seed][i]!=-1)
		{
			if(seen[graph[seed][i]]==0){
				dfs(seen,graph[seed][i]);
			}
		}
	}
	path2[count2]=seed;
	count2++;
}
int main(){
	int seen[nood]={0};
	int start =0;
	dfs(seen,start);
	printf("行きがけ\n");
	for(int i=0;i<nood;i++)
	{
		printf(" %d",path1[i]);
	}
	printf("\n帰りがけ");
	for(int i=0;i<nood;i++)
	{
		printf(" %d",path2[i]);
	}
	printf("\n");
}
