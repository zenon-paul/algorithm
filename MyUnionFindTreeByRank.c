#include<stdio.h>//高さによる変更
void iu(int* x,int* r, int size) {
	for (int i = 0; i < size; i++)
	{
		x[i] = i;
		r[i] = 0;
	}
}
int root(int* x, int n) {
	if (x[n] == n)
	{
		return n;
	}
	else
	{
		x[n] =  root(x, x[n]);//経路短縮
		return x[n];
	}
}
int issame(int* x, int a, int b) {
	if (root(x, a) == root(x, b))
	{
		return 1;
	}
	else {
		return 0;
	}
}
void unit(int* x,int* r, int a, int b) {
	int aa = root(x, a);
	int bb = root(x, b);
	if (aa != bb)
	{
		printf("%d %d : %d %d\n",aa,bb,r[aa],r[bb]);
		if (r[aa] < r[bb])
		{
			x[aa] = bb;
		}
		else
		{
			x[bb] = aa;
			if (r[aa] == r[bb]) {
				r[aa]++;
			}
		}
	}
}
void un_unit(int* x,int* r, int a) {
	x[a] = a;
	r[a] = 0;
}
