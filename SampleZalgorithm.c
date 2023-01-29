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
int lcp(char* s,int z[]){
	int ss = count_char(s);
	int head = 1;
	z[0] = ss;
	while(head < ss)
	{
		int i = 0;
		while((s[i] == s[head+i])&&(s[head+i] != '\0'))
		{
			i++;
		}
		z[head] = i;
		int j = 1;
		while(1)
		{
			if(i <= j)
			{
				head++;
				break;
			}
			else if(i <= (j+z[j]))
			{
				head += j;
				break;
			}
			else
			{
				z[head+j] = z[j];
			}
			j++;
		}
	}
	return ss;
}
int main(){
	char* s = "abcabcabcabcabcabcabc";
	int z[SLIM] = {0};
	int ss = 0;
	ss = lcp(s,z);
	for(int i = 0;i < ss;i++)
	{
		printf("%d ",z[i]);
	}
	printf("\n");
}
