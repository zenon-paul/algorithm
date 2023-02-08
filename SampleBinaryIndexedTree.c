#include <stdio.h>
#include <stdlib.h>
#define ERROR INT16_MAX
int sum(int* x,int leavs,int i){
	if(i == 0)
	{
		return 0;
	}
	int s = 0;
	while(i)
	{
		s += x[i];
		i &= (i-1);
	}
	return s;
}
void add(int* x,int leavs,int i,int n){
	if((i <= 0)||(leavs < i))
	{
		return;
	}
	//printf("#");
	while(i <= leavs)
	{
		x[i] += n;
		i += (i & -i);
	}
}
int* init_bitree(int size,int* n){
	int leavs = 1;
	int* ibtree;
	while(leavs < size)
	{
		leavs *= 2;
	}
	*n = leavs;
	ibtree = (int*)malloc(sizeof(size)*(leavs+1));
	for(int i = 0;i < leavs;i++)
	{
		ibtree[i] = 0;
	}
	return ibtree;
}
int get_sum(int* x,int leavs,int l,int r){
	if((r <= 0)||(leavs < l))
	{
		return ERROR;
	}
	printf("?\n");
	int b = sum(x,leavs,r);
	int s = sum(x,leavs,l-1);
	printf("@b: %d s:%d\n",b,s);
	return b - s;
}
int main(){
	int* a;
	int size = 10;
	int leavs = 0;
	a = init_bitree(size,&leavs);
	
	add(a,leavs,5,5);
	add(a,leavs,3,5);
	add(a,leavs,9,-1);

	
	int result = get_sum(a,leavs,1,9);
	printf("%d \n",result);
}

