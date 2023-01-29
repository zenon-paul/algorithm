#include <stdio.h>
#define qel_lim 5
#define wide 20
int qel[qel_lim][2]={
	{1,7},
	{3,9},
	{0,15},
	{5,7},
	{2,6}
};
void imos(int x[qel_lim][2],int y[wide+1]){
	for(int i=0;i<qel_lim;i++)
	{
		y[x[i][0]]+=1;
		y[x[i][1]+1]+=-1;//これ!
	}
	for(int i=1;i<(wide+1);i++)
	{
		y[i]=y[i-1]+y[i];
	}
}
int main(){
	int result[wide+1]={0};
	imos(qel,result);
	for(int i=0;i<(wide+1);i++)
	{
		printf(" %d",result[i]);
	}
	
	printf("\n");
}
