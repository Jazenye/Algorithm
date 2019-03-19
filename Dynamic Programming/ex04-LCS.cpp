#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 1000

using namespace std;

int dp[MAX][MAX];
string A, B;
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> A >> B;
	int lenA = A.length();
	int lenB = B.length();
	A.insert(0, " ");
	B.insert(0, " ");
	cout << A << " " << B << endl;
	// 边界 
	for(int i = 0; i <= lenA; i++)
		dp[i][0] = 0;
	for(int i = 0; i <= lenB; i++)
		dp[0][i] = 0;
		
	// 状态转移方程 
	for(int i = 1; i <= lenA; i++) {
		for(int j = 1; j <= lenB; j++) {
			if(A[i] == B[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else 
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[lenA][lenB];
	return 0; 
} 
