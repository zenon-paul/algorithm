#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 12
#define INF INT_MAX
int min(int x, int y) {
	return x < y ? x : y;
}
int max(int x, int y) {
	return x < y ? y : x;
}
int* init_segtree(int* x, int size, int* n) {
	int leavs = 1;
	int* segtree;
	while (leavs < size)
	{
		leavs *= 2;
	}
	*n = leavs;
	printf("%d\n",leavs);
	segtree = (int*)malloc(sizeof(size)*(2 * leavs - 1));
	for (int i = 0; i < (sizeof(size)*(2 * leavs - 1)); i++)
	{
		segtree[i] = INF;
	}
	for (int i = 0; i < size; i++)
	{
		segtree[leavs - 1 + i] = x[i];
	}
	int k = leavs - 2;
	while (k >= 0)
	{
		segtree[k] = min(segtree[2 * k + 1], segtree[2 * k + 2]);
		k--;
	}
	return segtree;
}
int get_min(int* segtree, int s, int g, int current, int l, int r) {
	if ((r <= s) || (g <= l))
	{
		return INF;
	}
	else if ((s <= l) && (r <= g))
	{
		return segtree[current];
	}
	else
	{
		int x = get_min(segtree, s, g, 2 * current + 1, l, (r - l) / 2 + l);
		int y = get_min(segtree, s, g, 2 * current + 2, (r - l) / 2 + l, r);
		return min(x, y);
	}
}
void update(int* segtree, int leavs, int n, int i) {
	segtree[leavs - 1 + i] = n;
	int k = leavs - 1 + i;
	while (k > 0)
	{
		int pa = (k - 1) / 2;
		segtree[pa] = min(segtree[2 * pa + 1], segtree[2 * pa + 2]);
		k = pa;
	}
}
void disp(int* segtree, int leavs) {
	for (int i = 0; i < (2 * leavs - 1); i++)
	{
		printf("%d ", segtree[i]);
	}
	printf("\n");
}
int main() {
	int size = SIZE;
	int leavs = 0;
	int data[SIZE] = { 6,3,6,8,15,18,51,37,8,9,24,13 };
	int* body;
	body = init_segtree(data, SIZE, &leavs);
	disp(body, leavs);
	int n = get_min(body, 5, 8, 0, 0, leavs);
	printf("区間[5,8)min:%d\n", n);
	free(body);
}
