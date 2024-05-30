#include <stdio.h>
#define SLIM 100
#define TLIM 100
int count_char(char* x){
	int i = 0;
	while(x[i] != '\0')
	{
		i++;
	}
	return i;
}
void make_next_pos_table_loose(int table[256],char* t,int ts){
	for(int i = 0;i < ts;i++)
	{
		table[t[i]] = ts - 1 - i;
	}
}
void make_next_pos_table_tight(int table[],char* t,int ts){
	for(int tail = 0;tail < (ts-1);tail++)
	{
		int eq = 0;
		while((eq < tail)&&(t[ts-1-eq] == t[tail-eq]))
		{
			eq++;
		}
		if(eq == 0)
		{
			continue;
		}
		if(t[ts-eq-1] != t[tail-ts])
		{
			table[ts-1-eq] = ts-1-tail-ts+eq;
		}
	}
	
	int tail = -1;
	for(int tpos = ts-2;tpos >= 0;tpos--)
	{
		int eq = ts-1-tpos;
		int j = 0;
		while((j<ts)&&(t[j] == t[tpos+1+j]))
		{
			j++;
		}
		if(eq == tpos)
		{
			tail = eq - 1;
		}
		if(table[tpos] == -1)
		{
			table[tpos] = ts-1-tpos+ts-1-tail;
		}
	}
}
int detect(char* s,char* t,int* memo){
	int ss = count_char(s);
	int ts = count_char(t);
	int count = 0;
	int current_pos_s = ts - 1;
	int current_pos_t = ts - 1;
	int bmnext0[256] = {ts};
	int bmnext1[TLIM] = {-1};
	make_next_pos_table_loose(bmnext0,t,ts);
	make_next_pos_table_tight(bmnext1,t,ts);
	while(current_pos_s < ss)
	{
		if(s[current_pos_s] == t[current_pos_t])
		{
			if(current_pos_t == 0)
			{
				memo[count] = current_pos_s;
				count++;
				current_pos_s += ts;
				current_pos_t = ts-1;
				continue;
			}
			current_pos_s--;
			current_pos_t--;
		}
		else
		{
			int rest;
			if(bmnext0[s[current_pos_s]]>bmnext1[current_pos_t])
			{
				rest = bmnext0[s[current_pos_s]];
			}
			else
			{
				rest = bmnext1[current_pos_t];
			}
			if(rest > ts-1-current_pos_t)
			{//bmnext[s[current_pos_s]] + 1 + current_pos_t < tsだと戻る
				current_pos_s += rest;
			}
			else
			{
				current_pos_s += ts - current_pos_t;
			}
			current_pos_t = ts - 1;
		}
	}
	return count;
}
int main(){
	char* s = "abcabcabxabcabcababcabcabcdabcxabcaxabcabc";
	char* t = "abcabc";
	int memo[100] = {-1};
	int count = 0;
	count = detect(s,t,memo);
	printf("c%d \n",count);
	for(int i = 0;i < count;i++)
	{
		printf("%d ",memo[i]);
	}
	printf("\n");
}
