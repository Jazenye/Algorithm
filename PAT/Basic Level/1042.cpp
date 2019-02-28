#include <iostream>    
#include <cctype> 
using namespace std;    

int count[201];
int main() {  
	string s;
	getline(cin, s);
	

	// 运用hash的思想，先将小写字母的ASCII码当做数组下标存入数组中计数
	int len = s.length();
	for(int i = 0; i < len; i++){
		if(isalpha(s[i])){ 
			count[tolower(s[i])]++;
		}
	}
	
	// 逆序查找出现最多的字符是为了遇到并列情况时输出ASCII码较小的小写字符
	int max = 0, ch;
	for(int i = 200; i >= 0; i--){
		if(max <= count[i]){
			max = count[i];
			ch = i;
		}
	}
	
	cout << (char)ch << " " << max; 

	return 0;
} 

 
