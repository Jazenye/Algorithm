#include <iostream>    
#include <string> 
using namespace std;    

int team[1001];
int main() {  
	int n, score, num, maxscore = 0, maxnum;
	string s;
	
	// 用find('-')找到团队编号从字符转为数字，并应用Hash的方法想家即可
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s >> score;
		num = stoi(s.substr(0, s.find('-')));
		team[num] += score;
	}
	
	for(int i = 0; i < 1001; i++){
		if(maxscore < team[i]){
			maxscore = team[i];
			maxnum = i;
		}
	}
	
	cout << maxnum << " " << maxscore;
	
	return 0;
} 

 
