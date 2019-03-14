#include <iostream>  
#include <vector> 
#include <algorithm>
#include <cstdio>

using namespace std;
struct mooncake {
	int no, sale;
};
bool cmp(mooncake a, mooncake b) {
	return a.sale == b.sale ? a.no < b.no : a.sale > b.sale;
}
int main() {
	int n, m, temp; cin >> n >> m; 
	vector<mooncake> v(n);
	// n为月饼种类，m为参与统计的城市数量 
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> temp;
			v[j].sale += temp;
			v[j].no = j + 1;
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	int flag = 0;
	for(int i = 0; i < n; i++) {
		if(i < n - 1 && v[i].sale != v[i+1].sale) 
			flag = 1;
		if(flag || i == n -1) {
			cout << v[i].sale << endl;
			for(int j = 0; j <= i; j++) {
				if(j != 0) cout << " ";
				cout << v[j].no;
			}
			break;
		}
	}
	
	return 0;
}
