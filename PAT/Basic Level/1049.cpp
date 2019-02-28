#include <iostream>   
using namespace std;    
  
int main() {  
	int n;
	double sum = 0, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){ 
		scanf("%lf", &m);
		sum += m * (i + 1) * (n - i);
	}
	
	printf("%.2f", sum); 
	return 0;
} 

 
