void iu(int* x,int size){
	for(int i=0;i<size;i++)
	{
		x[i]=i;
	}
}
int root(int* x,int n){
		if(x[n]==n)
		{
			return n;
		}
		else
		{
			return root(x,x[n]);
		}
}
int same(int* x,int a,int b){
	if(root(x,a)==root(x,b))
	{
		return 1;
	}
	else{
		return 0;
	}
}
void unit(int* x,int a,int b){
	int aa=root(x,a);
	int bb=root(x,b);
	if(aa!=bb)
	{
		if(a<b)
		{
			x[b]=a;
		}
		else
		{
			x[a]=b;
		}
	}
}
void un_unit(int* x,int a){
	x[a]=a;
}
