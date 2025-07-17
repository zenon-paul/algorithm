#include <stdio.h>

int count_char(char* x){
	int i = 0;
	while(x[i] != '\0')
	{
		i++;
	}
	return i;
}
int detect(char* s,char* t,int memo[]){
	int ss = count_char(s);
	int ts = count_char(t);
	int count = 0;
	for(int i = 0;i <= (ss-ts);i++)
	{
		for(int j = 0;j < ts;j++)
		{
			if(s[i+j] == t[j])
			{
				if(j == (ts-1))
				{
					memo[count] = i;
					count++;
				}
			}
			else
			{
				break;
			}
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
