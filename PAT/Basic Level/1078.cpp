#include <iostream> 
#include <string>
#include <cctype>
#include <cstdio>

using namespace std;

int main() {
	char code;
	string str, result = "";
	cin >> code;
	getchar();
	getline(cin, str);
	
	int len = str.length();
	if(code == 'C') { 
		int cnt = 1;
		for(int i = 0; i < len; i++) { 
			// 判断是否与后一个字符相同， 若相同则计数，否则输出该字符
			if(i < len && str[i] == str[i + 1]) {
				cnt++;
				continue;
			}
			string ch = cnt == 1 ? "" : to_string(cnt);
			cnt = 1;
			result += ch + str[i];
		}
	} else {
		int cnt = 0;
		for(int i = 0; i < len; i++) {
			if(str[i] >= '0' && str[i] <= '9') {
				cnt = cnt * 10 + (str[i] - '0');
				continue;
			}
			// 如果cnt = 0说明前面没有数字，那就修改为1，便于打印
			// 打印完后, cnt的值应当重置 
			if(cnt == 0) cnt = 1;
			for(int j = 1; j <= cnt; j++)
				result += str[i];
			cnt = 0;
		}
	}
	cout << result;
	return 0;
}
