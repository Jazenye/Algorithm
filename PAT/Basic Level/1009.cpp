#include <iostream> 
#include <stack>
#include <algorithm>

#include <cstdio>
using namespace std; 

int main() { 

	freopen("in.txt", "r", stdin);
	
	string s;
	stack<string> v;
	while(cin >> s)
		v.push(s);
	
	for(int i=0; !v.empty(); i++){
		if(i != 0) cout << " ";
		cout << v.top();
		v.pop();
	}
	
    return 0;
}
