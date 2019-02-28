#include <iostream>     
#include <string> 
using namespace std;    

// s1表示低位，s2表示高位，s2[0]用不到，但是可以凑一位数方便获取
string s1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string s2[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main() {  
	int n, num, flag = 0;
	string s, result;
		
	cin >> n;
	getchar(); // 用getchar去掉一个换行符，否则无法获取正常输入
	for(int i = 0; i < n; i++){
		getline(cin, s);
		result = "";
		num = flag = 0;
		
		// if语句下是火星文转地球文
		if(isalpha(s[0])){
			result = s.substr(0, 3);
			// 先截取字符串前三位，flag表示从高位或者低位获取
			for(int j = 0; j < 13; j++){
				if(result == s2[j]){
					num = j * 13;
					flag = 2;
					break;
				}
				if(result == s1[j]){
					num = j;
					flag = 1;
					break;
				}
			}
			
			// 判断是0或者13整数倍这样的特殊情况	
			if(flag == 2 && s.size() > 5) {  
				result = s.substr(4, 3);
				for(int j = 0; j < 13; j++) { 
					if(result == s1[j]) {
						num += j;  
						break;
					}
				}
			}
			cout << num;
		} else {
			num = stoi(s);  
			// 先判断高位, 再判断低位是否为0 
			if(num / 13 != 0 && num % 13 != 0)
				result = s2[num / 13] + " " + s1[num % 13];
			else if (num / 13 != 0 && num % 13 == 0) 
				result = s2[num / 13];
			else 
				result = s1[num % 13];
			cout << result;
		} 
		if(i != n - 1) cout << endl;
	}

	return 0;
} 

 
