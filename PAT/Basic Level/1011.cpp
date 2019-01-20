#include <iostream>    
using namespace std; 
 
int main() {  
	int n;
	long long int a, b, c;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%lld%lld%lld", &a, &b, &c);
		if(i != 0) printf("\n");
		printf("Case #%d: %s", i+1, a+b>c? "true":"false");
	} 
	
    return 0;
} 

