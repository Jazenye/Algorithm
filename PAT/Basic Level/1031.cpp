#include <iostream>    
using namespace std;    

char m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int weigh[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}; 
string v[101];
int main() {  
	int n, cnt = 0, tmp, flag = 0; 
	string str;
	
	cin >> n;
	for(int i=0; i < n; i++){
		tmp = flag = 0; 
		cin >> str;
		for(int j=0; j<str.length()-1; j++){ 
			if(str[j] >= '0' && str[j] <= '9'){ 
				tmp += weigh[j]*(str[j] - '0');
			} else {
				flag = 1;
				break;
			}	
		} 
		
		if(flag == 1){
			v[cnt++] = str; 
			continue;
		}  
		if(m[tmp % 11] == str[17]) 
			continue;
		v[cnt++] = str;
	}
	
	if(cnt != 0){
		for(int i=0; i<cnt; i++){
			if(i != 0) cout << endl;
			cout << v[i]; 
		}
	} else {
		cout << "All passed";
	}
	
	return 0; 
} 

 
