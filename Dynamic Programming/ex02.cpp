#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 1000

using namespace std;

int A[MAX], dp[MAX];
int main() {
//	freopen("in.txt", "r", stdin);
	int n, maxSum = 0; 
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> A[i];
	// 边界
	dp[0] = A[0]; 
	// 状态转移方程来计算dp
	for(int i = 1; i < n; i++) 
		dp[i] = max(dp[i-1]+A[i], A[i]);
	// 比较出最大序列和 
	for(int i = 0; i < n; i++)
		if(maxSum < dp[i])
			maxSum = dp[i];
	cout << maxSum;
	return 0; 
} 
