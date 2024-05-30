#include <stdio.h>
#define SLIM 100
#define TLIM 100
typedef unsigned long long ull;
int count_char(char* x){
	int i = 0;
	while(x[i] != '\0')
	{
		i++;
	}
	return i;
}
void make_table(char* t,ull mask[256],int ts){
	for(int i = 0;i < ts;i++)
	{
		mask[t[i]] = (1 << i) | mask[t[i]];//これこの形出ないと意味ないので注意
	}
}
int detect(char* s,char* t,int memo[]){
	int ss = count_char(s);
	int ts = count_char(t);
	int count = 0;
	ull mask[256] = {0};
	ull stetas = 0;
	ull goal = 1 << (ts-1);//とにかく左シフトが上位桁への移動と覚えとく
	make_table(t,mask,ts);
	for(int i = 0;i < ss;i++)
	{
		stetas = (stetas << 1) | 1;
		stetas = stetas & mask[s[i]];
		if((stetas&goal) != 0)
		{
			memo[count] = i - ts + 1;
			count++;
		}
	}
	return count;
}
int main(){
	char s[100] = "abcabcabxabcabcababcabcabcdabcxabcaxabcabc";
	char t[10] = "abcabc";
	int c = 0;
	int memo[10] = {0};
	c = detect(s,t,memo);
	printf("c%d\n",c);
	for(int i = 0;i < c;i++)
	{
		printf("%d ",memo[i]);
	}
	printf("\n");
}
/*
　オートマトンをビットで再現するには取り得る全状態の数分だけマスクを作る
　そのマスクは例えば状態aがi j k番目に来るべきならマスクのi j k 桁目を1にしておくそして上記のように回していくと正しい順番で状態が変化していった時のみゴールのビットに1がつく
*/
