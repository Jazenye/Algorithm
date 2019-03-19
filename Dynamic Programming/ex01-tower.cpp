#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 1000

using namespace std;

int f[MAX][MAX], dp[MAX][MAX];
int main() {
//	freopen("in.txt", "r", stdin);
	int n; cin >> n;
	// 输入数塔 
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= i; j++)
			cin >> f[i][j];
	// 边界
	for(int i = 1; i <= n; i++)
		dp[n][i] = f[n][i];
	// 从 n - 1层开始用状态转移方程向上计算
	for(int i = n - 1; i >= 1; i--)
		for(int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + f[i][j];
	cout << dp[1][1] << endl;
	return 0; 
} 
