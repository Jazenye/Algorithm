#include <iostream> 
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int main() { 
	string table, s1, s2;
	cin >> table >> s1 >> s2;
	int len = table.length();
	s1.insert(0, len - s1.length(), '0');
	s2.insert(0, len - s2.length(), '0'); 
	
	// 前面就是把短的字符串补0
	// 下面是判断是否有进位，如果有进位 则要在这个位置上+1 
	vector<int> v;
	bool isAdding = false;
	int carry = 0;
	for(int i = len - 1; i >= 0; i--) { 
		int num = (s1[i] - '0') + (s2[i] - '0');
		int t = table[i] == '0' ? 10 : (table[i] - '0'); 
		if(isAdding) {
			num++;
			isAdding = false;
		}
		if(num >= t) {
			isAdding = true;                         
			num -= t;
		}
		v.push_back(num);
	}
	if(isAdding) 
		v.push_back(1);
	
	string result = "";
	int flag = 0;
	for(int i = v.size() - 1; i >= 0; i--) {
		if(v[i] != 0 || flag == 1) {
			flag = 1;
			result += v[i] + '0';
		}
	} 
	if(flag == 0) {
		cout << 0;
		return 0;
	}
	cout << result;
	
	return 0;
}
