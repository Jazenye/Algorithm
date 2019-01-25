#include <iostream>     
#include <stack> 
using namespace std;  
 
int main() {  
	int a, b, c, d, tmp;
	cin >> a >> b >> d;
	stack<int> s;
	c = a + b;
	
	while(c != 0){
		tmp = c % d;
		s.push(tmp);
		c = c/d; 
	} 
	
	if(s.empty()){
		cout << 0;
	}
	else{
		while(!s.empty()){
			cout << s.top();
			s.pop();
		}
	}
	
    return 0;
} 

