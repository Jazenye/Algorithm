#include <iostream>
#include <string>
using namespace std; 

int main() {
	int n, B = 0, S = 0, G;
	
	cin >> n;
	
	G = n % 10;
	S = n / 10 % 10;
	B = n / 10 / 10;
	
	for(int i=0; i<B; i++)
		cout << 'B';
	for(int i=0; i<S; i++)
		cout << 'S';
	for(int i=1; i<=G; i++)
		cout << i;
		
    return 0;
}
