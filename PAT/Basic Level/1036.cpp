#include <iostream>   
using namespace std;    

int main() {  
	int n, high;
	char ch;
	cin >> n >> ch;
	high = (n+1)/2 - 2; //四舍五入后去掉首尾两行 
	
	// 1、3循环是打印首尾
	for(int i = 0; i < n; i++) cout << ch;
	cout << endl;

	// 打印中间部分
	for(int i = 0; i < high; i++){ 
		for(int j = 0; j < n; j++){
			if(j == 0 || j == n - 1)
				cout << ch;
			else 
				cout << " ";
		}
		cout << endl;
	}

	for(int i = 0; i < n; i++) cout << ch;
	 
	
	return 0; 
} 

 
