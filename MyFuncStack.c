#include<MyStack.h>
int s_push(d_stack* x,int input) {
	if ((x->tail + 1) > (x->leng - 1)) {
		return 0;
	}
	x->body[x->tail + 1] = input;
	x->tail++;
	return 1;
}
int s_pop(d_stack* x,int* result) {
	if (x->tail < 0) {
		return 0;
	}
	*result = x->body[x->tail];
	x->tail--;
	return 1;
}
void is( d_stack* x, int* b, int l) {
	x->leng = l;
	x->tail = -1;
	x->body = b;
}
