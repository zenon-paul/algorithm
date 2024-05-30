#include <stdio.h>
#include <stdlib.h>
#include "union_find_tree.h"
#include "heap_sort.h"
#define node 10
#define inf 214748364
int graph[node][node]={
	{inf,5,2,3,inf,inf,inf,inf,inf,inf},
	{5,inf,inf,inf,inf,inf,1,inf,inf,inf},
	{2,inf,inf,inf,inf,3,7,inf,inf,inf},
	{3,inf,inf,inf,1,1,inf,inf,inf,inf},
	{inf,inf,inf,1,inf,4,inf,inf,inf,9},
	{inf,inf,3,1,4,inf,inf,inf,8,inf},
	{inf,1,7,inf,inf,inf,inf,2,1,inf},
	{inf,inf,inf,inf,inf,inf,2,inf,6,inf},
	{inf,inf,inf,inf,inf,8,1,6,inf,3},
	{inf,inf,inf,inf,9,inf,inf,inf,3,inf},
};
void  ie(d_num* x,int y[node][node]){
	int q=0;
	for(int i=0;i<node;i++)
	{
		for(int j=i+1;j<node;j++)
		{
			if(y[i][j]!=inf){
			(x+q)->index=1<<i;
			(x+q)->index+=1<<(j);
			(x+q)->num=y[i][j];
			q++;
			}
		}
	}
}
int count_edge(int y[node][node]){
	int q=0;
	for(int i=0;i<node;i++)
	{
		for(int j=0;(j+i+1)<node;j++)
		{
			if(y[i][i+j+1]!=inf){
			q++;
			}
		}
	}
	return q;
}
int main(){
	int edges;
	edges=count_edge(graph);
	d_num* e;
	d_num* r;
	int count=0;
	int uni[node]={0};
	int cost=0;
	e=(d_num *)malloc(sizeof(d_num)*edges);
	r=(d_num *)malloc(sizeof(d_num)*edges);
	ie(e,graph);
	iu(uni,node);
	sort(e,edges);
	int a,b;
	for(int i=0;i<edges;i++)
	{
		int rest=0;
		int restm=0;
		for(int m=0;m<node;m++)
		{
			rest=(e+i)->index>>m;
			if( 1 & rest )
			{
				a=m;
				break;
			}
		}
		for(int k=1;k<node;k++)
		{
			rest=rest>>1;//これ
			if(  1 & rest )
			{
				b=a+k;
				break;
			}
		}
		//閉路判定→追加の順番で
		//
		//
		if(same(uni,a,b) == 0)
		{
			unit(uni,a,b);
			(r+count)->index=(e+i)->index;
			(r+count)->num=(e+i)->num;
			cost+=(e+i)->num;
			count++;
		}
	printf("\ncount%d\n",count);
	}
	
	for(int i=0;i<(node-1);i++){
	printf("\nrindex:%d num:%d",(r+i)->index,(r+i)->num);
	}
	printf("\n%d\n",cost);
	free(e);
	free(r);
	//unitを小←大としておくことで閉路判定の不具合
	//直した詳しくはunion_find_tree関数unitを参照
	//prequeueの構造体の型に合わせろ
}

