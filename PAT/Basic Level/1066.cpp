#include <iostream> 
#include <cstdio>

using namespace std;

int main(){
    int m, n, a, b, replace, temp;
    scanf("%d %d %d %d %d", &m, &n, &a, &b, &replace); 
     
    for(int i = 0; i < m; i++) {
    	for(int j = 0; j < n; j++) { 
    		scanf("%d", &temp);
    		if(temp >= a && temp <= b)
    			temp = replace; 
    		if(j != 0) printf(" ");
    		printf("%03d", temp);
		}
		if(i != m - 1) printf("\n");
	}
	return 0;
}

