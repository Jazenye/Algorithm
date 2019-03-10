#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n;
	string d, result;
	cin >> d >> n;
	// i 代表处理第i项, 如果n = 1则无需处理，直接输出 
	for(int i = 2; i <= n; i++) { 
		int len = d.length();
		int cnt = 1;
		result = "";
		for(int j = 0; j < len;j++) {
			if((j < len - 1) && d[j] == d[j + 1]) {
				cnt++;
				continue;
			}
			result += d[j] + to_string(cnt);
			cnt = 1;
		}
		d = result;
	}
	cout << d;
	return 0;
}
