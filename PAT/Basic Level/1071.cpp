#include <iostream>   
#include <cstdio> 

using namespace std;    

int main() {  
	int x, K, n1, n2, b, t; 
	// x 是赠送筹码， K 需要处理的游戏次数,
	// n1, n2是计算机先后给出的整数， b,t 分别表示玩家赌大和小 
	// x 为玩家当前持码量 
	cin >> x >> K;
	
	for(int i = 0; i < K; i++) {
		cin >> n1 >> b >> t >> n2;
		if(x < t) {
			cout << "Not enough tokens.  Total = " << x << "." << endl;
			continue;
		}

		// 异或运算，相同出0相异出1
		if(!((n1 < n2) ^ b)) {
			cout << "Win " << t << "!  ";
			x += t;
		} else {
			cout << "Lose " << t << ".  ";
			x -= t;
		}
		cout << "Total = "	<< x << "." << endl;
		if(x <= 0) {
			cout << "Game Over.";
			return 0;
		}
	}
	return 0;
} 

 
