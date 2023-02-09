#include<stdio.h>
#include<limits.h>
#define INF INT_MAX
#define DEINF INT_MIN
#define NLIM 10
#define ELIM 100
int edge[ELIM][3] = {
	{0,3,4},
	{0,4,5},
	{0,2,1},
	{3,6,4},
	{4,6,2},
	{4,5,2},
	{2,1,1},
	{6,7,5},
	{5,7,2},
	{1,5,4},
	{1,7,8}
};
int dist[NLIM];
int path[NLIM];
void init_dist(int n,int e,int s) {
	for (int i = 0; i < n;i++) {
		dist[i] = INF;
		path[i] = -1;
	}
	dist[s] = 0;
}
int bellmanford(int n,int e,int s,int g) {
	int flag = 1;
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < e;j++) {
			if (dist[edge[j][1]] > dist[edge[j][0]] + edge[j][2]) {
				dist[edge[j][1]] = dist[edge[j][0]] + edge[j][2];
				path[edge[j][1]] = edge[j][0];
				if (i == n-1) {
					flag = 0;
				}
			}
		}
	}
	return flag ? dist[g] : DEINF;
}
int get_path(int p[],int s,int g) {
	int count = 0;
	int current = g;
	for (; current != s;) {
		p[count] = current;
		current = path[current];
		count++;
	}
	return count;
}
int main() {
	int n = 8;
	int e = 11;
	int memo[NLIM] = { 0 };
	init_dist(n,e,0);
	int d = bellmanford(n,e,0,7);
	printf("%d\n",d);
	int node = get_path(memo,0,7);
	for (int i = node-1; i >= 0;i--) {
		printf("%d ",memo[i]);
	}
}
