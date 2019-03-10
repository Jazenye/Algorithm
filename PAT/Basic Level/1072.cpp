#include <iostream>   
#include <vector>
#include <cstdio> 

using namespace std;    

struct stu {
	string name;
	int num;
	bool flag = false; // 代表学生是否带了违禁物品，默认没带 
	vector<int> v;
};
int main() {  
	int n, m, cnt = 0, id;
	cin >> n >> m;
	
	vector<int> ban(m);
	vector<stu> s(n);
	for(int i = 0; i < m; i++) 
		cin >> ban[i];
	for(int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].num;
		for(int j = 0; j < s[i].num; j++) {
			cin >> id;
			// 第 i 个学生的 第 j 个物品，与禁止物品的ID进行比较 
			for(int k = 0; k < m; k++) {
				if(id == ban[k]) {
					cnt++;
					s[i].v.push_back(id);
					s[i].flag = true; 
				}
			}
		}
	}
	
	int people = 0;
	for(int i = 0; i < n; i++) {
		if(s[i].flag) { 
			cout << s[i].name << ":";
			for(int j = 0; j < s[i].v.size(); j++)
				printf(" %04d", s[i].v[j]); 
			people++;
			cout << endl;
		}
	}
	printf("%d %d", people, cnt); 
	return 0;
} 

 
