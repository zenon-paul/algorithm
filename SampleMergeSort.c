#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENG 8
void copy(int* from,int* to,int s,int g){
	for(int i = s;i <= g;i++)
	{
		to[i-s] = from[i];
	}
}
void sort_ao(int *x,int size){
	int h[LENG] = {0};
	int t[LENG] = {0};
	int hh = size/2;
	int tt = size - size/2;
	if(size > 1){
		copy(x,h,0,hh-1);
		copy(x,t,hh,size-1);
		sort_ao(h,hh);
		sort_ao(t,tt);
		int xh = 0;
		int xt = 0;
		for(int i = 0;i < size;i++)
		{
			if(((h[xh] < t[xt])&&(xh < hh)&&(xt < tt))||(xt >= tt))
			{
				x[i] = h[xh];
				xh++;
			}
			else if(((h[xh] >= t[xt])&&(xt < tt))||(xh >= hh))
			{
				x[i] = t[xt];
				xt++;
			}
		}
	}
}
int main(){
	int test[LENG] = {0};
	srand((unsigned int)time(NULL));
	for(int i = 0;i < LENG;i++)
	{
		test[i] = rand()%10;
	}
	for(int i = 0;i < LENG;i++)
	{
		printf("%d ",test[i]);
	}
	printf("\n");
	sort_ao(test,LENG);
	for(int i = 0;i < LENG;i++)
	{
		printf("%d ",test[i]);
	}
	printf("\n");
}

