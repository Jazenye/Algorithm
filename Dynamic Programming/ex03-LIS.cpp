#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 1000

using namespace std;

int A[MAX], dp[MAX];
int main() {
//	freopen("in.txt", "r", stdin);
	int n; 
	vector<int> v;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> A[i];
	int ans = -1; // 记录最大的dp[i] 
	for(int i = 1; i <= n; i++) {
		dp[i] = 1;  // 边界初始条件，先假设每个元素自成一格子序列 
		for(int j = 1; j < i; j++)
			if(A[i] >= A[j] && (dp[j] + 1 > dp[i]))
				dp[i] = dp[j] + 1;
		ans = max(ans, dp[i]);		
	}
	cout << ans << endl;  // 打印LIS长度 
	return 0; 
} 
