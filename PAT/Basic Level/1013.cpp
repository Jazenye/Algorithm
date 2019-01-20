#include <iostream>    
using namespace std; 

// 判断是否为素数：如果是素数则返回1 
int isPrime(int a){
	for(int j=2; j*j<=a; j++)
		if(a%j == 0) return 0;
	return 1;
}
int ary[10001];
int main() {  
	int m, n, count, i=1, flag = 0;
	cin >> m >> n;
	
	// 从1开始判断次数是否为素数
	// 用count 记录这是第几个素数
	// 用flag 来记录格式,flag的处理比较细腻 可以学习 
	while(count <= n){
		if(isPrime(i)){
			count++;
			if(count > m){
				if(flag%10 != 0) cout << " ";
				flag++;
				cout << i;
				if(flag%10 == 0) cout << "\n";
			}
		} 
		i++;
	}
	
    return 0;
} 

