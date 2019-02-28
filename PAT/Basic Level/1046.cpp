#include <iostream>     
using namespace std;    

int main() {  
	int n, alose = 0, blose = 0, aout, ahand, bout, bhand, tmp;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> aout >> ahand >> bout >> bhand;
		if(ahand != bhand){
			tmp = aout + bout;
			if(ahand == tmp) blose++;
			if(bhand == tmp) alose++;
		} 
	}
	
	cout << alose << " " << blose;
	
	return 0;
} 

 
