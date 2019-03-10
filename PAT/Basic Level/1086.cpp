#include <iostream> 
#include <cstdio>

using namespace std;

int main() { 
	int a, b, result = 0; 
	cin >> a >> b;
	string s = to_string(a * b);
	for(int i = s.length() - 1; i >= 0; i--)  
		result = result * 10 + (s[i] - '0'); 
	cout << result;
	
//	reverse(s.begin(), s.end());
//	printf("%d", stoi(s));
	
	return 0;	
}
