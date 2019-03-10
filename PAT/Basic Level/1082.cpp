#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	int n, id, x, y, min = 20000, max = 0, first, last;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d", &id, &x, &y);
		int temp = x * x + y * y;
		if(temp < min) {
			min = temp;
			first = id;
		}
		if(temp > max) {
			max = temp;
			last = id;
		}
	}
	
	printf("%04d %04d", first, last);
	
}
