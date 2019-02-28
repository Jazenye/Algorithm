#include <iostream>   
#include <vector>
#include <algorithm> 
using namespace std;    

int v[100005];
int main() {  
	int n, count = 0, max = 0;
	 
	scanf("%d", &n);
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	
	sort(b.begin(), b.end());
	for(int i = 0; i < n; i++){
		if(a[i] == b[i] && b[i] > max){
			v[count++] = b[i];
		}
		if(a[i] > max)
			max = a[i];
	}
	
	
	printf("%d\n", count); 
	for(int i = 0; i < count; i++){
		if(i != 0) printf(" ");
		printf("%d", v[i]);
	}
	printf("\n"); 
	return 0;
} 

 
