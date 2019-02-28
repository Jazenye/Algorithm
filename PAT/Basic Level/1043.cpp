#include <iostream>
using namespace std;

int ch[6];
int main() {
	string s, str = "PATest", result;
	cin >> s;
	int len = s.length();

	// ch数字用来记录PATest这六个字母的余量
	for(int i = 0; i < len; i++){
		for(int j = 0; j < 6; j++){
			if(s[i] == str[j])
				ch[j]++;
		}
	}
	int flag = 1;  // 表示数组内还有字母剩余
	while(flag == 1){
		flag = 0;
		for(int i = 0; i< 6; i++){
			if(ch[i] > 0){
				ch[i]--;
				result += str[i];
				flag = 1;  // 若发生过改变，说明数组内还可能有字母剩余
			}
		}
	}

	cout << result;
	return 0;
}


//运用map
//int main() {
//    int map[128] = {0}, c;
//    while ((c = cin.get()) != EOF) map[c]++;
//    while (map['P'] > 0 || map['A'] > 0 || map['T'] > 0 || map['e'] > 0 || map['s'] > 0 || map['t'] > 0) {
//        if (map['P']-- > 0) cout << 'P';
//        if (map['A']-- > 0) cout << 'A';
//        if (map['T']-- > 0) cout << 'T';
//        if (map['e']-- > 0) cout << 'e';
//        if (map['s']-- > 0) cout << 's';
//        if (map['t']-- > 0) cout << 't';
//    }
//    return 0;
//}

