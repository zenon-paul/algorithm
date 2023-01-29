#include<MyStack.h>
int push(int y,d_stack* x){
    if((x->tail+1) > (x->leng-1))
    {
	return 0;
    }  
    x->body[x->tail+1]=y;
    x->tail++;
    return 1;
}
int pop(int* y,d_stack* x){
    if(x->tail<=-1)
    {
        return 0;
    }
    *y = x->body[x->tail];
    x->tail--;
    return 1;
}
void is(d_stack *x,int *y,int n){
    x->tail=-1;
    x->leng=n;
    x->body=y;
}
