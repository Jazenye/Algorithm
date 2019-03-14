#include <iostream>  
#include <unordered_map> 
#include <vector>
#include <cstdio>

using namespace std;

int main() {
	string s1, s2, s;
	getline(cin, s1);
	getline(cin, s2); 
	
	s = s1 + s2;
	int len = s.length(), cnt = 0;
	
	unordered_map<char, int> mp;
	vector<char> v;
	for(int i = 0; i < len; i++) {
		// 利用map去重，并用cnt 来记录该字符在数组中的下标（赋值给map）
		// 下标顺序即字符的出现顺序，按照vector的下标依次打印即可
		if(mp.count(s[i]) == 0) {
			mp[s[i]] = cnt++;
			v.push_back(s[i]);
		}
	}
	
	for(int i = 0; i < v.size(); i++)
		cout << v[i];
	
	return 0;
}
