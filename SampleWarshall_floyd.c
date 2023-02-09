#include<stdio.h>
#include<limits.h>
#define INF INT_MAX
#define NLIM 10
#define ELIM 100
int dp[NLIM][NLIM];
int graph[ELIM][3] = {
	{0,1,5},
	{1,3,2},
	{2,3,20},
	{0,2,3},
	{0,3,8}
};
int min(int x,int y) {
	return x < y ? x : y;
}
void warshall_floyd(int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}
void init_dp(int n, int edge){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = INF;
		}
	}
	for (int i = 0; i < edge;i++) {
		dp[graph[i][0]][graph[i][1]] = graph[i][2];
		dp[graph[i][1]][graph[i][0]] = graph[i][2];
	}
	for (int i = 0; i < n;i++) {
		dp[i][i] = 0;
	}
}
int main() {
	int n = 4;
	int e = 5;
	init_dp(n,e);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%12d", dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	warshall_floyd(n);
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			printf("%12d",dp[i][j]);
		}
		printf("\n");
	}
}
