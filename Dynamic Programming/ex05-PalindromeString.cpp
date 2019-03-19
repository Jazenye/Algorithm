#include <iostream>
#include <cstdio>
#define MAX 1000

using namespace std;

int dp[MAX][MAX];
string S;
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> S;
	int len = S.length(), ans = 1;
	// 边界 
	for(int i = 0; i < len; i++) {
		dp[i][i] = 1;
		if(i < len - 1 && S[i] == S[i + 1]) {
			dp[i][i + 1] = 1;
			ans = 2;  // 初始化注意当前最长回文子串长度 
		}
	}
		
	// 状态转移方程 
	for(int l = 3; l <= len; l++) {  // 枚举子串的长度 
		for(int i = 0; i + l - 1 < len; i++) {  // 枚举子串的起始端点 
			int j = i + l - 1;  // 子串的右端点 
			if(S[i] == S[j] && dp[i + 1][j - 1] == 1) {
				dp[i][j] = 1;
				ans = l; // 更新最长回文子串长度 
			}
		}
	}
	cout << ans;
	return 0; 
} 
