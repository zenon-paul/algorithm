#include <stdio.h>
#include <stdlib.h>
#define lim 100
#define sss 8
typedef struct data{
	int index;
	int num;
}d_num;
d_num* nums;
int* date;
void in(d_num* x,int* y,int size){
	for(int i=0;i<size;i++)
	{
		(x+i)->index=i;//x[i].index OK!
		(x+i)->num=y[i];
	}
}
int chmin(int a,int b){
	if(a<b)
	{
		return 1;
	}
	else return 0;
}
int chmax(int a,int b){
	if(a>b)
	{
		return 1;
	}
	else return 0;
}
void make_heap(d_num* x,int broad){
	int restnum;
	int restind;
	for(int i=broad;i>0;)
	{
		if(chmin((x+i)->num,(x+(i-1)/2)->num))
		{
			break;
		}
		else
		{
			restnum=(x+(i-1)/2)->num;
			restind=(x+(i-1)/2)->index;
			
			(x+(i-1)/2)->num=(x+i)->num;
			(x+(i-1)/2)->index=(x+i)->index;
			
			(x+i)->num=restnum;
			(x+i)->index=restind;
			i=(i-1)/2;
		}
	}
}
void remake_heap(d_num* x,int broad){
	int prchild;
	int prindex;
	for(int i=0;(2*i+1)<=broad;)
	{
		if(2*i+2<=broad){
			if(chmin((x+2*i+1)->num,(x+2*i+2)->num))
			{
				if(chmin((x+i)->num,(x+2*i+2)->num))
				{
					prchild=(x+2*i+2)->num;
					prindex=(x+2*i+2)->index;
			
					(x+2*i+2)->num=(x+i)->num;
					(x+2*i+2)->index=(x+i)->index;
			
					(x+i)->num=prchild;
					(x+i)->index=prindex;
					i=2*i+2;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(chmin((x+i)->num,(x+2*i+1)->num))
				{
					prchild=(x+2*i+1)->num;
					prindex=(x+2*i+1)->index;
			
					(x+2*i+1)->num=(x+i)->num;
					(x+2*i+1)->index=(x+i)->index;
			
					(x+i)->num=prchild;
					(x+i)->index=prindex;
					i=2*i+1;
				}
				else
				{
					break;
				}
			
			}
		}
		else
		{
			if(chmin((x+i)->num,(x+2*i+1)->num)){
					prchild=(x+2*i+1)->num;
					prindex=(x+2*i+1)->index;
			
					(x+2*i+1)->num=(x+i)->num;
					(x+2*i+1)->index=(x+i)->index;
			
					(x+i)->num=prchild;
					(x+i)->index=prindex;
					i=2*i+1;
				}
				else
				{
					break;
				}
		}
	}
}
int add_num_to_heap(d_num* x,int tail){
	make_heap(x,tail);
	tail++;
	return tail;
}
int recon_heap(d_num* x,int tail){
	int restnum;
	int restind;
	restnum=(x+tail-1)->num;
	restind=(x+tail-1)->index;
	
	(x+tail-1)->num=x->num;
	(x+tail-1)->index=x->index;
	
	x->num=restnum;
	x->index=restind;
	tail--;
	remake_heap(x,tail-1);
	return tail;
}
int main(){
	int size=sss;
	nums=(d_num*)malloc(sizeof(d_num )*size);
	if(nums==NULL)
	{
		printf("FAIL!!");
		return 0;
	}
	date=(int*)malloc(sizeof(int)*size);
	if(date==NULL)
	{
		printf("FAIL!!");
		return 0;
	}
	for(int i=0;i<size;i++)
	{
		printf(" %d:%d ",i,date[i]=(rand()%100));
	}
	printf("\n------------------------------------------------\n");
	printf("結果\n");
	in(nums, date,size);
	for(int i=0;i<size;i++)
	{
		(nums+i)->num=date[i];
	}
	for(int i=0;i<size;)
	{
		i=add_num_to_heap(nums,i);
	}
	for(int i=size;i>1;)
	{
		i=recon_heap(nums,i);
	}
	for(int i=0;i<size;i++)
	{
		printf
		(" %d:%d",(nums+i)->index,(nums+i)->num);
	}
	free(nums);
	free(date);
}
