#include <stdio.h>
int mod(int x,int y){
	return (x%y + y)%y;
}
int exgcd(int a,int b,int* x,int* y){// ax + by = gcd(a,b)
	int d = a;
	if(b != 0)
	{
		d =exgcd(b,a%b,y,x);
		*y -= (a/b)*(*x);
	}
	else
	{
		*x = 1;
		*y = 0;
	}
	return d;
}
int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;
}

int chineserem_for_2(int a,int r1,int b,int r2){
	int x = 0;
	int y = 0;
	int g = exgcd(a,b,&x,&y);
	int l = a*b/g;
	return mod(r2*a*x+r1*b*y,l);
}
int chineserem_for_n(int m[],int r[],int size){
	int rr = 0;
	int mm = 1;
	for(int i = 0;i < size;i++){
		int x = 0;
		int y = 0;
		int g = exgcd(mm,m[i],&x,&y);
		if((r[i]-rr)%g != 0)
		{
			return -1;
		}
		int rest = (r[i]-rr)/g*x%(m[i]/g);
		rr += mm * rest;
	   mm *= m[i]/g;
	}
	return mod(rr,mm);
}
int main(){
	int x = 0;
	int y = 0;
	int g = gcd(57,38);
	int m[2] = {5,3};
	int r[2] = {3,2};
	//int f = exgcd(38,19,&x,&y);
	int c = chineserem_for_n(m,r,2);
	printf("x:%d y:%d\n",x,y);
	printf("g:%d\n",g);
	printf("c:%d\n",c);
}
