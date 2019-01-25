#include <iostream>     
using namespace std;  

int main() { 
	int ary[10] = {0}, flag = 0;
	string s; 
	cin >> s; 

	for(int i=0; i<s.length(); i++) 
		++ary[s[i]-'0'];  
	
	for(int i=0; i<10; i++){
		if(ary[i] != 0){
			if(flag) cout << endl;
			cout << i << ":" << ary[i];
			flag = 1;
		}
	}
	
    return 0;
} 

