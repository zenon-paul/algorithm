#include<MyQueue.h>
int put(int y,d_queue* x){
    if(((x->tail+2)%x->leng) == x->head)
    {
    return 0;
    }
    x->body[(x->tail+1)%x->leng]=y;
    x->tail++;
    return 1;
}
int get(int *y,d_queue* x){
    if((x->tail+1)%x->leng==x->head)
    {
	return 0;
    }
    *y=x->body[(x->head)%x->leng];
    x->head++;
    return 1;
}
void iq(d_queue *x,int *y,int n){
    x->tail=-1;
    x->head=0;
    x->leng=n;
    x->body=y;
}
