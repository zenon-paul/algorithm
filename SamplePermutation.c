#include <stdio.h>//1_ind
#define LIM 10
int nums[LIM+1] = {0};
int index(int num[LIM],int n){
	int ind = 0;
	for(int i = 0;i < n;i++)
	{
		ind *= (n-i);
		for(int j = i+1;j<n;j++)
		{
			if(num[i]>num[j])
			{
				ind++;
			}
		}
	}
	return ind;
}
void permutation(int* seen,int seed,int n,int depth){
	seen[seed] = 1;
	nums[depth] = seed;
	for(int i = 1;i <= n;i++){
		if(seen[i] == 0){
			permutation(seen,i,n,depth+1);
			seen[i] = 0;
		}
	}
	if(depth == n-1)
	{
		for(int i = 0;i<n;i++){
			printf("%d ",nums[i]);
		}
		printf("  ind:%d",index(nums,4));
		printf("\n");
	}
}
void clear(int *seen){
	for(int i = 0;i<LIM+1;i++)
	{
		seen[i] = 0;
	}
}
int main(){
	int seen[LIM+1] = {0};
	int n = 4;
	for(int i = 1;i<=n;i++)
	{
		printf("@%d\n",i);
		permutation(seen,i,n,0);
		clear(seen);
	}//reset!!
}
