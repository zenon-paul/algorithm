#include <stdio.h>//セグ木はデータの一点変更に便利
#include <stdlib.h>//1-indexがいいらしい
#include <limits.h>
#define SIZE 12
#define INF INT16_MAX
int min(int x,int y){
	return x < y ? x : y;
}
int max(int x,int y){
	return x < y ? y : x;
}

int* init_segtree(int* x,int size,int* n){
	int leavs = 1;
	int* segtree;
	while(leavs < size)
	{
		leavs *= 2;
	}
	*n = leavs;
	segtree = (int*)malloc(2*sizeof(int)*leavs - 1);//inf de init siro!!
	for(int i = 0;i < (2*sizeof(size)*leavs - 1);i++)
	{
		segtree[i] = 0;
	}
	for(int i = 0;i < size;i++)
	{
		segtree[leavs-1+i] = x[i];
	}
	int k = leavs - 2;
	while(k >= 0)
	{
		segtree[k] = segtree[2*k+1] + segtree[2*k+2];
		k--;
	}
	return segtree;
}
int* init_lazy(int leavs){
	int* x;
	x = (int*)malloc(2*sizeof(int)*leavs-1);
	for(int i = 0;i < leavs;i++)
	{
		x[i] = 0;
	}
	return x;
}

void eval(int* segtree,int* lazy,int current,int l,int r){
	if(lazy[current] != 0){
		segtree[current] += lazy[current];
		if((r-l)>1)
		{
			lazy[2*current+1] += lazy[current]/2;
			lazy[2*current+2] += lazy[current]/2;
		}
		lazy[current] = 0;
	}
}

void add(int* segtree,int* lazy,int num,int s,int g,int current,int l,int r){
	eval(segtree,lazy,current,l,r);
	if((r <= s)||(g <= l))
	{
		return;
	}
	else if((s <= l)&&(r <= g))
	{
		lazy[current] += (r-l)*num;
		eval(segtree,lazy,current,l,r);
	}
	else
	{
		add(segtree,lazy,num,s,g,2*current+1,l,l+(r-l)/2);
		add(segtree,lazy,num,s,g,2*current+1,l+(r-l)/2,r);
		segtree[current] = segtree[2*current+1] + segtree[2*current+2];
	}
}

int get_sum(int* segtree,int* lazy,int s,int g,int current,int l,int r){
	if((r <= s)||(g <= l))
	{
		return 0;
	}
	eval(segtree,lazy,current,l,r);
	if((s <= l)&&(r <= g))
	{
		return segtree[current];
	}
	else
	{
		int x = get_sum(segtree,lazy,s,g,2*current+1,l,l+(r-l)/2);
		int y = get_sum(segtree,lazy,s,g,2*current+1,l+(r-l)/2,r);
		return x + y;
	}
}

void disp(int* segtree,int leavs){
	for(int i = 0;i < (2*leavs-1);i++)
	{
		printf("%d ",segtree[i]);
	}
	printf("\n");
}
int main(){
	int size = SIZE;
	int leavs = 0;
	int data[SIZE] = {6,3,6,8,15,18,51,37,8,9,24,13};
	int* body;
	int* attached;
	body = init_segtree(data,SIZE,&leavs);
	attached = init_lazy(leavs);
	disp(body,leavs);
	disp(attached,leavs);
	add(body,attached,3,5,12,0,0,leavs);
	disp(body,leavs);	
	disp(attached,leavs);
	int f = get_sum(body,attached,5,10,0,0,leavs);
	printf("\n:%d\n",f);
	free(body);
	free(attached);
}
