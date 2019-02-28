#include <iostream>    
using namespace std;    

int main() {  
	int n, dayup, day;
	double eup, e, fullempty = 0, halfempty = 0;
	cin >> n >> eup >> dayup;
	for(int i = 0; i < n; i++) {
		cin >> day;
		int cnt = 0;
		for(int j = 0; j < day; j++){
			cin >> e;
			if(e < eup) cnt++;
		} 
		if(cnt > day / 2)  day > dayup ? fullempty++ : halfempty++; 
//		if(day > dayup && cnt > day/ 2)  fullempty++;  
//		else if(cnt > day / 2) halfempty++; 
	}
	 
	double hrate = halfempty / n * 100;
	double frate = fullempty / n * 100; 
	printf("%.1f%% %.1f%%", hrate, frate);
	
	return 0;
} 

 
