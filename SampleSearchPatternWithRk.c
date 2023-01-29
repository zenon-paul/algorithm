#include <stdio.h>
typedef unsigned long ull;
int count_char(char* x){
	int i = 0;
	while(x[i] != '\0')
	{
		i++;
	}
	return i;
}
int detect(char* s,char* t,int memo[]){
	int count = 0;
	int ss = count_char(s);
	int ts = count_char(t);
	ull shash = 0;
	ull thash = 0;
	unsigned long b = 100000007;
	ull k = 1;
	for(int i = 0;i < ts;i++)
	{
		k *=b;
	}
	for(int i = 0;i < ts;i++)
	{
		shash = shash*b + s[i];
	}
	for(int i = 0;i < ts;i++)
	{
		thash = thash*b + t[i];
	}
	for(int i = 0;i <= (ss-ts);i++)
	{
		if(shash == thash)
		{
			memo[count] = i;
			count++;
		}
		if(i < (ss-ts))
		{
			shash = shash*b + s[i+ts] - s[i]*k;
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
	printf("一致した回数%d\n",c);
	printf("一致した位置\n");
	for(int i = 0;i < c;i++)
	{
		printf("%d ",memo[i]);
	}
	printf("\n");
}
