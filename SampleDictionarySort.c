#include <stdio.h>
#include <stdlib.h>
#define leng_lim 20
typedef struct data_dictionary_sort{
	int size;
	int leng;
	int tail;
	char** body;
}d_dicsort;
void disp(d_dicsort* x);
void ids(d_dicsort* x,int s,int l){
	x->size = s;
	x->leng = l;
	x->tail = 0;
}
int chmin(char* s,char* t){
	int i = 0;
	while(s[i] == t[i])
	{
		if((s[i] == '\0')&&(t[i] == '\0'))
		{
			return 1;
		}
		i++;
	}
	if (s[i] <= t[i]){
		return 1;
	}
	else
	{
		return 0;
	}
}
int chmax(char* s,char* t){
	int i = 0;
	while(s[i] == t[i])
	{
		if((s[i] == '\0')&&(t[i] == '\0'))
		{
			return 1;
		}
		i++;
	}
	if (s[i] >= t[i]){
		return 1;
	}
	else
	{
		return 0;
	}
}
void swaps(char** s,char** t){
	char* rest;
	rest = *s;
	*s = *t;
	*t = rest;
}
void make_heap(d_dicsort* x){
	int end = x->tail - 1;       
	for(int i = end;i > 0;)
	{
		if(chmin((x->body)[i],(x->body)[(i-1)/2]))
		{
			swaps(&((x->body)[i]),&((x->body)[(i-1)/2]));
			i = (i-1)/2;
		}
		else
		{
			break;
		}
	}
}
void remake_heap(d_dicsort* x){
	int end = x->tail - 1;
	for(int i = 0;(i*2+1) <= end;){
		if((i*2+2) <= end)
		{
			int restposi;
			if(chmin((x->body)[i*2+1],(x->body)[i*2+2]))
			{
				restposi = i*2+1;
			}
			else
			{
				restposi = i*2+2;
			}
			if(chmin((x->body)[restposi],(x->body)[i]))
			{
				swaps(&((x->body)[restposi]),&((x->body)[i]));
				i = restposi;
			}
			else
			{
				break;
			}
		}
		else
		{
			if(chmin((x->body)[i*2+1],(x->body)[i]))
			{
				swaps((&(x->body)[i*2+1]),&((x->body)[i]));
				i = i*2+1;
			}
			else
			{
				break;
			}
		}
	}
}
void add_string_to_heap(d_dicsort* x){
	for(int i = 0;i < x->size;i++)
	{
		x->tail++;
		make_heap(x);
	}
}
void recon_heap(d_dicsort* x){
	for(int i = 0;i < x->size;i++)
	{
		swaps(&(x->body[0]),&((x->body)[x->tail-1]));
		x->tail--;
		remake_heap(x);
	}
}
void sort(d_dicsort* x){
	add_string_to_heap(x);
	recon_heap(x);
}
void disp(d_dicsort* x){
	for(int i = 0;i < x->size;i++)
	{
		for(int j = 0;(x->body)[i][j];j++)
		{
			printf("%c",(x->body)[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int strings = 10;
	d_dicsort property;
	property.body = (char**)malloc(sizeof(char*)*strings);
	ids(&property,5,20);
	(property.body)[0] = "rfijug";
	(property.body)[1] = "adx";
	(property.body)[2] = "ad";
	(property.body)[3] = "tscgt";
	(property.body)[4] = "rfhjug";
	sort(&property);
	disp(&property);
	printf("\n");
	free(property.body);
}
