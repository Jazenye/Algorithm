#include <iostream> 
#include <algorithm>
#include <cstdio>

using namespace std;

// 判断是否是回文数 
bool isTurn(string s) { 
	int len = s.length(); 
	for(int i = 0; i < len / 2; i++) {
		if(s[i] != s[len - i -1])
			return false;
	}
	return true;
}

// 10进制加法 
string numAdd(string s1, string s2) {
	string result = s1;
	int carry = 0;
	for(int i = s1.size() - 1; i >= 0; i--) {
		result[i] = ((s1[i] - '0') + (s2[i] - '0') + carry) % 10 + '0';
		carry = ((s1[i] - '0') + (s2[i] - '0') + carry) / 10;
	}
	if(carry != 0) result = "1" + result;
	return result;
}

// 字符串翻转 
string rev(string s) {
	reverse(s.begin(), s.end());
	return s;
}

int main() { 
	int step = 1;
	string s, revStr;
	cin >> s;
	
	// 设定为11次就是为了判断 第10次的结果而已 
	for(; step <= 11; step++) {
		if(isTurn(s)) {
			cout << s << " is a palindromic number.";
			return 0;
		}
		else if(step == 11) {
			cout << "Not found in 10 iterations.";
			return 0;
		}
		revStr = rev(s);
		string result = numAdd(s, revStr);
		for(int i = 0; i < revStr.length(); i++) {
			if(revStr[i] != '0') {
				revStr.erase(0, i);
				break;
			}
		}
		
		cout << s << " + " << revStr << " = " << result << endl;
		s = result;
	}
	
	return 0;
}
