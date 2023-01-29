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
void make_next_pos_table(char* t,int ts,int kmpnext[]){
	kmpnext[0] = -1;
	int j = kmpnext[0];
	for(int i = 1;i <= ts;i++)
	{
		while((j >= 0)&&(t[i-1] != t[j]))
		{
			j = kmpnext[j];
		}
		j++;
		if(t[i] == t[j])
		{
			kmpnext[i] = kmpnext[j];
		}
		else
		{
			kmpnext[i] = j;
		}
	}
}
int detect(char* s,char* t,int memo[]){
	int ss = count_char(s);
	int ts = count_char(t);
	int count = 0;
	int current_pos_s = 0;
	int current_pos_t = 0;
	int kmpnext[TLIM] = {0};
	make_next_pos_table(t,ts,kmpnext);
	while(current_pos_s < ss)
	{
		if(s[current_pos_s] == t[current_pos_t])
		{
			if(current_pos_t == (ts-1))
			{
				memo[count] = current_pos_s-ts+1;
				count++;
				current_pos_s++;
				current_pos_t = kmpnext[ts];
				continue;
			}
			current_pos_t++;
			current_pos_s++;
		}
		else
		{
			if(kmpnext[current_pos_t] == kmpnext[0])
			{
				current_pos_s++;
				current_pos_t = 0;
			}
			else
			{
				current_pos_t = kmpnext[current_pos_t];
			}
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
	printf("一致した回数%d \n",count);
	printf("一致した位置\n");
	for(int i = 0;i < count;i++)
	{
		printf("%d ",memo[i]);
	}
	printf("\n");
}
