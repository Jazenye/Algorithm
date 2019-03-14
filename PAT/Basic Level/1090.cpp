#include <iostream>  
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	map<int, vector<int> > mp;
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	for(int i = 0; i < m; i++) {
		int k; cin >> k;
		vector<int> vk; //用来存放该行中有多少个不相容物品，只有不相容物品的数量大于1才开始比较 
		int flag = 1;  // flag = 1 表示没有不相容物品，输出yes 
		for(int j = 0; j < k && flag; j++) {
			int id; cin >> id;
			// 这个物品在不相容列表清单中，把它加入比较序列 vk 
			if(mp.count(id) != 0) 
				vk.push_back(id);
		}
		int len = vk.size();
		if(len > 1) {
			// 从不相容物品列表中遍历（for int j）
			// 找到map中相应的不相容列表清单进行比较 (for int a, for int b)
			for(int j = 0; j < len && flag; j++) {
				int l = mp[vk[j]].size();
				for(int a = 0; a < l && flag; a++) {
					for(int b = j + 1; b < len && flag; b++) {
						if(mp[vk[j]][a] == vk[b]) 
							flag = 0; 
					}
				} 
			}
		}
		
		if(flag) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
