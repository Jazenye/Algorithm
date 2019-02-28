#include <iostream> 
#include <cctype> 
using namespace std;    

int main() {  
	string s1, s2;
	int isup = 0;
	// 用getline是为了避免第一行输入为空时的边界情况
	getline(cin, s1);
	getline(cin, s2); 
	 
	for(int i = 0; i < s1.length(); i++) {  
		if(s1[i] == '+') { 
			isup = 1;  // 上档键坏了
			break;
		}
	}

	for(int i = 0; i < s2.length(); i++) {
		// 1. 大写字母无法输出 
		if(isup == 1 && isupper(s2[i]))
			continue;
			
		// 2. 在s1中找到该字符 
		if(s1.find(s2[i]) != string::npos) 
			continue; 
			
		// 3. 在s1中找到该字符的大写字母 
		if(isalpha(s2[i]) && s1.find(toupper(s2[i]))!= string::npos) 
			continue; 
		cout << s2[i]; 
	}
	 
	return 0; 
} 

 
