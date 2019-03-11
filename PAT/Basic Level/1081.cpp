#include <iostream>  
#include <cctype>
#include <cstdio>

using namespace std;
 
int main() {
	freopen("in.txt", "r", stdin);
	int n;
	bool flagOfAlpha = false, flagOfNum = false, flagOfIllegal = false;
	string s;
	cin >> n; getchar();
	for(int i = 0; i < n; i++) {
		flagOfAlpha = flagOfNum = flagOfIllegal = false;
		getline(cin, s);
		int len = s.length();
		if(len < 6) {
			cout << "Your password is tai duan le." << endl;
			continue;
		}
		for(int j = 0; j < len; j++) { 
			if(isalpha(s[j])) 
				flagOfAlpha = true;  
			}
			else if(isdigit(s[j])) 
				flagOfNum = true;  
			else if(s[j] != '.') { 
				flagOfIllegal = true;
				break;
			}  
		}
		if(flagOfIllegal) 
			cout << "Your password is tai luan le." << endl;
		else if(!flagOfNum) 
			cout << "Your password needs shu zi." << endl; 
		else if(!flagOfAlpha) 
			cout << "Your password needs zi mu." << endl; 
		else 
			cout << "Your password is wan mei." << endl;
	}
	
	return 0;
}
