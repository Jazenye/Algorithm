#include <iostream>   
#include <cmath>
#include <cstdio>

using namespace std;

void cmp(int a, double b) {
	if(a == b) cout << " Ping";
	else if(a < b) cout << " Cong";
	else cout << " Gai";
}
int main() { 
	int m, x, y; cin >> m >> x >> y;
	int maxa = 9;
	
	for(int i = 10; i <= 99; i++) { 
		int b = i / 10 + i % 10 * 10;
		double c = b * 1.0 / y; 
		if(fabs(i - b) == (c * x)) {
			if(maxa < i)
				maxa = i;
		} 
	}
	if(maxa == 9) cout << "No Solution";
	else {
		cout << maxa; 
		cmp(m, maxa);
		cmp(m, maxa / 10 + maxa % 10 * 10);
		cmp(m, (maxa / 10 + maxa % 10 * 10) * 1.0 / y);
	}
	
	return 0;
}
