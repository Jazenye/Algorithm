#include <iostream>   
#include <vector>
#include <algorithm> 
using namespace std;    

int main() {  
	long long int p;
	int n, result = 0;
	
	scanf("%d%lld", &n, &p); 
	vector<long long int> v(n);
	for(int i = 0; i < n; i++) 
		scanf("%lld", &v[i]);  
	sort(v.begin(), v.end());  
	 
	// i 代表最小值的边界,最小值边界不断提升
	// 因为是为了找最大的result，所以下一次j只要从i的result个后面开始找即可 
	for(int i=0; i<n; i++){
		for(int j = result+i; j < n; j++){
			if(v[j] <= p * v[i]){ 
				if(j-i+1 > result) result = j-i+1;
			} else {
				break;
			}
		}
	}
	
	cout << result;
	return 0; 
} 

 
