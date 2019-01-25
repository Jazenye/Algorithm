#include <iostream>   
using namespace std;    

int main() {  
	int c1, c2, sum;
	// 根据总秒数计算时、分、秒
	int hour, min, s;
	cin >> c1 >> c2;
	sum = ((c2 - c1) + 50) / 100;
	hour = sum / 3600;
	min = sum % 3600 / 60;
	s = sum % 3600 % 60;
	printf("%02d:%02d:%02d", hour, min, s);
	 
	return 0;
} 

 
