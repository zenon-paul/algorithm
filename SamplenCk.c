#include <stdio.h>
int nCk(int n,int k){
	if((k == 0)||(n == k))
	{
		return 1;
	}
	else
	{
		return nCk(n-1,k) + nCk(n-1,k-1);
	}
}
int main(){
	printf("%d ",nCk(6,3));
}
