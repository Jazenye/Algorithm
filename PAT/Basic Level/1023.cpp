#include <iostream>       
using namespace std;  
 
int main() {  
	int a[10];
	for(int i=0; i<10; i++) cin >> a[i]; 
	

	// 先找到第一个不为0的数， 后计数-1再按照从小到大输出
	for(int i=1; i<10; i++){
		if(a[i] != 0){
			cout << i;
			--a[i];
			break;
		}
	}
	
	for(int i=0; i<10; i++){
		while(a[i] != 0){
			cout << i;
			a[i]--;
		}
	}
	
    return 0;
} 

