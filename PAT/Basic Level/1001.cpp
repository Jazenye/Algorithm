#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int n, count;
	count = 0;
	scanf("%d", &n);
	while(n != 1){
		count++;
		if(n%2 == 0)
			n = n/2;
		else
			n = (3*n+1)/2;
	}
	
	cout<<count;
	return 0;
}
