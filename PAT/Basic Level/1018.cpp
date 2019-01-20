#include <iostream>
#include <math.h>

using namespace std;

// acount 记录对应出招顺序上的字母所赢的次数
char ary[3] = {'B', 'C', 'J'};
int acount[3] = {0, 0 , 0};
int bcount[3] = {0, 0 , 0};
int main() {
	char a, b;
	// awin,bwin 分别记录甲乙总胜场
	// amaxwin, bmaxwin分别记录甲乙胜利最多的手势； ka,kb为中间变量 用于转换
	int n, ka = 0, kb = 0, tmpa, tmpb, awin = 0, bwin = 0;
	int amaxwin = 0, bmaxwin = 0;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> a >> b;
		for(int j=0; j<3; j++){
			if(a == ary[j]) tmpa = j;
			if(b == ary[j]) tmpb = j;
		}

		// 布、剪刀、石头，相邻的序号小的赢，若序号差2 即B和J，则判序号小的赢
		if(abs(tmpa - tmpb) == 1){
			if(tmpa < tmpb){
				awin++;
				acount[tmpa]++;
			}
			else{
				bwin++;
				bcount[tmpb]++;
			}
		}
		else if( abs(tmpa - tmpb) == 2){
			if(tmpa > tmpb){
				awin++;
				acount[tmpa]++;
			}
			else{
				bwin++;
				bcount[tmpb]++;
			}
		}
	}

	for(int i=0; i<3; i++){
		if(amaxwin < acount[i]){
			amaxwin = acount[i];
			ka = i;
		}
		if(bmaxwin < bcount[i]){
			bmaxwin = bcount[i];
			kb = i;
		}
	}


	cout << awin << " " <<  n - awin - bwin << " " << bwin << endl;
	cout << bwin << " " <<  n - awin - bwin << " " << awin << endl;
	cout << ary[ka] << " " << ary[kb];

    return 0;
}

