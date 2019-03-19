#include <iostream>   
#include <map>
using namespace std; 
int main() {
	// 这map开的与数组无异。。。。。
	map<int, float> mp;
	for(int i = 0; i < 2; i++) {
		int k, exp;
		float coe;
		cin >> k;
		for(int j = 0; j < k; j++) {
			cin >> exp >> coe;
			mp[exp] += coe;
		}
	}
	int cnt = 0;
	for(auto it = mp.rbegin(); it != mp.rend(); it++)
		if(it->second != 0.0)
			cnt++;
	
	printf("%d", cnt);
	for(auto it = mp.rbegin(); it != mp.rend(); it++)
		if(it->second != 0.0)
			printf(" %d %.1f", it->first, it->second); 
	return 0;
}
