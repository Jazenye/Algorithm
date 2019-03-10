#include <iostream>
#include <map> 
using namespace std;

int main() { 
	int n, temp;
	map<int, int> mp;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		mp[abs(i - temp)]++;
	}
	for(auto it = mp.rbegin(); it != mp.rend(); it++) 
		if(it->second > 1)
			printf("%d %d\n", it->first, it->second); 
	return 0;
}
