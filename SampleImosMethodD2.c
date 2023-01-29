#include <stdio.h>
#define qel_lim 8
#define wide_h 10
#define wide_w 10
#define lim 50
int qel[qel_lim][4]={
	{0,0,4,5},
	{2,3,4,4},
	{2,2,6,6},
	{1,0,7,3},
	{5,5,3,4},
	{1,1,7,7},
	{6,4,3,5},
	{1,1,8,8}
};
void imos(int x[qel_lim][4],int y[lim][lim]){
	for(int i=0;i<qel_lim;i++)
	{
		
		y[qel[i][1]][qel[i][0]]+=1;
		y[qel[i][1]][qel[i][0]+qel[i][2]]+=-1;
		y[qel[i][1]+qel[i][3]][qel[i][0]]+=-1;
		y[qel[i][1]+qel[i][3]][qel[i][0]+qel[i][2]]+=1;
	}
	for(int i=0;i<(wide_h+1);i++)       //------->
	{
		for(int j=1;j<(wide_w+1);j++){
			y[i][j]=y[i][j]+y[i][j-1];
		}
	}
	for(int i=0;i<(wide_w+1);i++)		// |
	{					// |
		for(int j=1;j<(wide_h+1);j++){  // v
			y[j][i]=y[j][i]+y[j-1][i];
		}
	}
}
int main(){
	int result[lim][lim]={0};
	imos(qel,result);
	for(int i=0;i<(wide_h+1);i++)
	{
		for(int j=0;j<(wide_w+1);j++)
		{
			printf(" %3d",result[i][j]);
		}
		printf("\n");
	}
}
