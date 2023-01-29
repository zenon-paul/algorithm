#include<MyPriorityQueue.h>
void ip(d_prqueue* x,int* b,int s){
    x->body=b;
    x->size=s;
    x->tail=0;
}
int chmin(int a,int b){
    if(a<b)
    {
        return 1;
    }
    else return 0;
}
int chmax(int a,int b){
    if(a>b)
    {
	return 1;
    }  
    else return 0;
}
void swap(int* x,int* y){
    int restnum;
    restnum=*x;
    *x=*y;
    *y=restnum;
}
void make_heap(d_prqueue* x,int broad){
    int restnum;
    for(int i=broad;i>0;)
    {
        if(chmax(x->body[i],x->body[(i-1)/2]))
        {
            break;
        }
        else 
        {
	    swap(&(x->body[(i-1)/2]),&(x->body[i]));
	    i=(i-1)/2;
        }
    }
}
void remake_heap(d_prqueue * x,int broad){
    int prchild;
    for(int i=0;(2*i+1)<=broad;)
    {
	if(2*i+2<=broad){
	    if(chmax(x->body[2*i+1],x->body[2*i+2]))
	    {
		if(chmax(x->body[i],x->body[2*i+2]))
       	        {
		    swap(&(x->body[2*i+2]), &(x->body[i]));
		    i=2*i+2;
                }
                else
                {
		    break;
                }
            }
            else
	    {
		if(chmax(x->body[i],x->body[2*i+1]))
	        {  
		swap(&(x->body[2*i+1]), &(x->body[i]));
		i=2*i+1;
                }
	        else
	        {
		    break;
		}
	    }
	}
	else
	{
	    if(chmax(x->body[i],x->body[2*i+1]))
	    {
	        swap(&(x->body[2*i+1]), &(x->body[i]));
	        i=2*i+1;
	    }
	    else
	    {
		break;
	    }
	}
    }
}
int put_check(d_prqueue* x){
    if(x->size<=x->tail)
    {
	return 1;
    }
    return 0;
}
int get_check(d_prqueue* x){
    if(0>=x->tail)
    {
	return 1;
    }
    return 0;
}
int put(d_prqueue *x,int y){
    if(put_check(x))
    {
	return 0;
    }
    x->body[x->tail]=y;
    x->tail++;
    make_heap(x,x->tail-1);
    return 1;
}
int get(d_prqueue *x,int* y){
    if(get_check(x))
    {
        return 0;
    }
    *y=x->body[0];
    x->body[0]=x->body[x->tail-1];
    x->tail--;
    remake_heap(x,x->tail-1);
    return 1;
}

