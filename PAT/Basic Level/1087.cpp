#include <iostream> 
#include <cstdio>
using namespace std;
int ary[100000] = {0};
int main() { 
	int n, cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) 
		ary[i / 2 + i / 3 + i / 5]++;
	for(int i = 0; i <= 100000; i++) 
		if(ary[i])
			cnt++;
	cout << cnt;
//	set<int> s;
//	for (int i = 1; i <= n; i++)
//		s.insert(i / 2 + i / 3 + i / 5);
//	printf("%d", s.size());
	return 0;	
}
