#include <iostream>
#include <string> 
using namespace std;
int main() { 
	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		int k, flag = 1; cin >> k; 
		for(int n = 1; n < 10; n++) {
			//K为n位数，则要比较乘积结果的n位数
			int sum = n * k * k;  
			// 截取结果的最后几位作为字符串进行比较
			string kStr = to_string(k), sumStr = to_string(sum);
			string endStr = sumStr.substr(sumStr.length() - kStr.length());
			if(kStr == endStr) {
				cout << n << " " << sum << endl;
				flag = 0;
				break;
			}
		} 
		if(flag) cout << "No\n";
	}
	
	return 0;
}
