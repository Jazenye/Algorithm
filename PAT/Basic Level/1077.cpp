#include <iostream> 
#include <cstdio>

using namespace std;

int main() { 
	int n, m, g1, g2, sum;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		int score = 0, cnt = -2; // cnt记录有效成绩,要去除最低和最高分 
		int min = m, max = 0, sum = 0;
		cin >> g2;
		for(int j = 0; j < n - 1; j++) {
			cin >> score;
			if(score < 0 || score > m)  continue;
			if(min > score)  min = score;
			if(max < score)  max = score;
			sum += score;
			cnt++;
		}
		
		cout << int((((sum - max - min) * 1.0 /cnt) + g2) / 2 + 0.5) << endl;
	}
	
	
	return 0;
}
