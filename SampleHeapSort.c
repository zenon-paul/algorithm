typedef struct data{
	int index;
	int num;
}d_num;
void in(d_num* x,int* y,int size){
	for(int i=0;i<size;i++)
	{
		(x+i)->index=i;//x[i].index OK!
		(x+i)->num=y[i];
	}
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
	int rest = *x;
	*x = *y;
	*y = rest;
}
void make_heap(d_num* x,int broad){
	for(int i=broad;i>0;)
	{
		if(chmin((x+i)->num,(x+(i-1)/2)->num))
		{
			break;
		}
		else
		{
			swap(&((x+(i-1)/2)->num),&((x+i)->num));
			swap(&((x+(i-1)/2)->index),&((x+i)->index));
			i=(i-1)/2;
		}
	}
}
void remake_heap(d_num* x,int broad){
	for(int i=0;(2*i+1)<=broad;)
	{
		if(2*i+2<=broad){
			if(chmin((x+2*i+1)->num,(x+2*i+2)->num))
			{
				if(chmin((x+i)->num,(x+2*i+2)->num))
				{
					swap(&((x+2*i+2)->num),&((x+i)->num));
					swap(&((x+2*i+2)->index),&((x+i)->index));
					i=2*i+2;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(chmin((x+i)->num,(x+2*i+1)->num))
				{
					swap(&((x+2*i+1)->num),&((x+i)->num));
					swap(&((x+2*i+1)->index),&((x+i)->index));
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
			if(chmin((x+i)->num,(x+2*i+1)->num)){
					swap(&((x+2*i+1)->num),&((x+i)->num));
					swap(&((x+2*i+1)->index),&((x+i)->index));
					i=2*i+1;
				}
				else
				{
					break;
				}
		}
	}
}
int add_num_to_heap(d_num* x,int tail){
	make_heap(x,tail);
	tail++;
	return tail;
}
int recon_heap(d_num* x,int tail){
	swap(&((x+tail-1)->num),&(x->num));
	swap(&((x+tail-1)->index),&(x->index));
	tail--;
	remake_heap(x,tail-1);
	return tail;
}
void sort(d_num* x,int size){
	for(int i=0;i<size;)
	{
		i=add_num_to_heap(x,i);
	}
	for(int i=size;i>1;)
	{
		i=recon_heap(x,i);
	}
}
