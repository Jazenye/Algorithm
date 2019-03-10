#include <iostream>
#include <map> 

using namespace std;

int main() { 
	int n;
	string ans;
	cin >> n;
	getchar();
	map<char, int> transform;
	transform['A'] = 1;
	transform['B'] = 2;
	transform['C'] = 3;
	transform['D'] = 4;
	for(int i = 0; i < n; i++) {
		int result;
		getline(cin, ans); 
		// 处理单行答案， 以'-'作为界限，把字符串一点点截取掉
		for(int j = 0; j < 4; j++) {
			int pos = ans.find('-');
			if(ans[pos + 1] == 'T') { 
				result = transform[ans[pos - 1]];
				cout << result;
				break;
			} else {
				ans.erase(0, pos + 2);
			}
		}
	}
	
	return 0;
}

// 柳神三行搞定。。n 没有用，直接就找长度为3且含T的字符串就可以了。。
// string s;
// while (cin >> s)
// if(s.size() == 3 && s[2] == 'T') cout << s[0]-'A'+1; 
