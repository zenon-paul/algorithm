#include<stdio.h>
#include<limits.h>
#define INF INT_MAX
#define ELIM 1000
#define BLIM 1000
#define VLIM 110
typedef struct graph_data{
	int to;
	int cap;
}d_edge;
d_edge restgraph[VLIM][BLIM];
int e, v;
int start, goal;
void disp();
int min(int x,int y) {
	return x < y ? x : y;
}
void make_restgraph(int x[ELIM][3]) {
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < BLIM; j++) {
			restgraph[i][j].to = -1;
		}
	}
	for (int i = 0; i < e; i++) {
		int j = 0;
		while ((j < BLIM) && (restgraph[x[i][0]][j].to != -1)) {
			j++;
		}
		restgraph[x[i][0]][j].to = x[i][1];
		restgraph[x[i][0]][j].cap = x[i][2];
		int k = 0;
		while ((k < BLIM) && (restgraph[x[i][1]][k].to != -1)) {
			k++;
		}
		restgraph[x[i][1]][k].to = x[i][0];
		restgraph[x[i][1]][k].cap = 0;
	}
}
int dfs(int seen[VLIM],int seed,int f) {
	if (seed == goal) {
		return f;
	}
	int j = 0;
	seen[seed] = 1;
	while (restgraph[seed][j].to != -1){
		if ((seen[restgraph[seed][j].to] == 0)&&(restgraph[seed][j].cap > 0)) {
			int d =  dfs(seen,restgraph[seed][j].to, min(restgraph[seed][j].cap, f));
			if (d > 0) {
				restgraph[seed][j].cap -= d;
				int k = 0;
				while (restgraph[restgraph[seed][j].to][k].to != seed) {
					k++;
				}
				restgraph[restgraph[seed][j].to][k].cap += d;
				return d;
			}
		}
		j++;
	}
	return 0;
}
int ford_fullkerson() {
	int flow = 0;
	while (1) {
		int seen[VLIM] = { 0 };
		int f = dfs(seen,start,INF);
		if (f == 0) {
			return flow;
		}
		flow += f;
	}
}
void disp() {
	for (int i = 0; i < v;i++) {
		int j = 0;
		while ((restgraph[i][j].to != -1)&&(j<BLIM)) {
			printf("%d %d %d\n",i, restgraph[i][j].to, restgraph[i][j].cap);
			j++;
		}
	}
}
int main() {
	int input[ELIM][3] = {0};
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e;i++) {
		scanf("%d %d %d",&input[i][0],&input[i][1],&input[i][2]);
	}
	start = 0;
	goal = v-1;
	make_restgraph(input);
	int result = ford_fullkerson();
	printf("%d\n", result);
}
