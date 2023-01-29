#include <stdio.h>
#include "MyQueue.h"//自作関数　MyFuncQueue.s　を使用
#define lim 4
#define nood 11
int graph0[nood][lim]={
    {1,2,3},
    {4,5,-1},
    {-1,-1,-1},
    {6,-1,-1},
    {7,8,9}, 
    {-1,-1,-1},
    {-1,-1,-1},
    {10,-1,-1},
    {-1,-1,-1},
    {-1,-1,-1},
    {-1,-1,-1},
};
d_queue alis;
void bfs(int *dist,int seed){
    int hohe=0;
    while(get(&hohe,&alis)){
    	for(int i=0;i<lim;i++)
    	{
    	    if(graph0[hohe][i]==-1)
            {
	    	continue;
    	    }
    	    if(dist[graph0[hohe][i]]!=-1)
    	    {
	    	continue;
    	    }
    	    else
    	    {
	    	dist[graph0[hohe][i]]=dist[hohe]+1;
	    	put(graph0[hohe][i],&alis);
    	    }
    	}
    }
}
int main(){
    int dist[nood];
    for(int i=0;i<nood;i++)
    {
	dist[i]=-1;
    }
    int queue[nood*nood]={0};
    int seed=0;
    printf("%d以下の数"nood);
    scanf("%d",&seed);
    iq(&alis,queue,nood*nood);
    dist[0]=0;
    put(0,&alis);
    bfs(dist,seed);
    for(int i=0;i<nood;i++){
        printf("%d : %d\n",i,dist[i]);
    }
    return 0;
}
