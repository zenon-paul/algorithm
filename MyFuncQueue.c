#include<MyQueue.h>
int q_put(d_queue* x,int input) {
	if (((x->tail + 2) % x->leng) == (x->head)) {//((x->tail + 2) % x->leng) >= (x->head)この場合値が二度と入らなくなってしまうので==にしよう
		return 0;
	}
	x->body[(x->tail + 1) % x->leng] = input;
	x->tail++;
	return 1;
}
int q_get(d_queue* x,int* result) {
	if (((x->tail + 1) % x->leng) == x->head) {
		return 0;
	}
	*result = x->body[(x->head) % x->leng];
	x->head++;
	return 1;
}
void iq( d_queue* x, int* b, int l) {
	x->leng = l;
	x->tail = -1;
	x->head = 0;
	x->body = b;
}
