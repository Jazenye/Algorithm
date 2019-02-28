#include <iostream>
#include <map> 
using namespace std;    

// 此题用数组或者vector都很简单。。 用map只是为了练习用法
int main() {  
	int n, num, score, maxnum = 1, maxscore = 0;
	map<int, int> m;
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> num >> score;
		m[num] += score;
	}
	
	for(auto it = m.begin(); it != m.end(); it++){
		if(maxscore <= it->second){
			maxscore = it->second;
			maxnum = it->first;
		}
	}
	
	cout << maxnum << " " << maxscore;
	
	return 0; 
} 

 
