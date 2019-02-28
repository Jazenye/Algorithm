#include <iostream>    
using namespace std;    
 
int main() {  
	int n, num, sum = 0; 
	cin >> n;
	// 每个数当 n-1次个位与十位 
	for(int i = 0; i < n; i++){
		cin >> num;
		sum += (n - 1) * (num + num * 10);
	}
	
	cout << sum;
	return 0;
} 

 
