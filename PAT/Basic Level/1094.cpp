#include <iostream>  
#include <unordered_map> 
#include <vector>
#include <string> 

using namespace std;
// 判断是否为素数，注意0和1要单独判断 
bool isprime(int a) {
	if(a == 0 || a == 1) return false;
	for(int i = 2; i * i <= a; i++)
		if(a % i == 0)
			return false;
	return true;
}
int main() { 
	int l, k;
	string num;
	cin >> l >> k >> num;
	
	// 注意i的结束条件，需要保证判断位数满足长度K 
	for(int i = 0; i <= l - k; i++) { 
		string p = num.substr(i, k);
		int temp = stoi(p);
		if(isprime(temp)) { 
			cout << p;
			return 0;
		}
	}
	cout << 404;
	return 0;
}
