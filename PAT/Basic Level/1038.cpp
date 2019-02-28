#include <iostream>    
using namespace std;    
 
int ary[100005] = {0};
int main() {  
	int n, m, tmp; 
	// 用cin超时了。。 
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		ary[tmp]++;
	}
	
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &tmp);
		if(i != 0) printf(" ");
		printf("%d", ary[tmp]);
	}
	
	return 0; 
} 

 
