#include <iostream>  
#include <vector>  
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std; 
// 定义学生结构体，含考生编号：ID， 考试成绩：score， 考试等级：level 
struct stu {
	string id;
	int score;
};
// 考场结构体，含考场编号 testRoom， 考场人数 people 
struct classroom {
	string testRoom;
	int people;
};
// 根据题目规则制定的比较规则，分别适用于类型1与类型3 
bool cmp1(stu a, stu b) {
	return a.score != b.score ? a.score > b.score : a.id < b.id;
}
bool cmp3(classroom a, classroom b) {
	return a.people != b.people ? a.people > b.people : a.testRoom < b.testRoom;
}
int main() {
	int n, m; 
	cin >> n >> m;
	
	vector<stu> v(n);
	for(int i = 0; i < n; i++) 
		cin >> v[i].id >> v[i].score; 
	               
	for(int i = 1; i <= m; i++) {
		int type, cnt = 0, sum = 0; 
		string request;
//		scanf("%d", &type);
		cin >> type >> request;
		
		// isEmpty 判断符合条件的个数是否为空，默认为 没有符合条件的准考证 设为true 
		bool isEmpty = true;
		printf("Case %d: %d %s\n", i, type, request.c_str()); 
		if(type == 1) {
			sort(v.begin(), v.end(), cmp1);
			for(int j = 0; j < n; j++) {
				if(v[j].id[0] == request[0]) {
					isEmpty = false;
					printf("%s %d\n", v[j].id.c_str(), v[j].score); 
				}
			}
		} else if(type == 2) {
			for(int j = 0; j < n; j++) {
				// 2-4位是考场号 
				if(v[j].id.substr(1, 3) == request) {
					isEmpty = false;
					cnt++;
					sum += v[j].score; 
				}
			}
			if(!isEmpty)
				printf("%d %d\n", cnt, sum); 
		} else {
			vector<classroom> c;
			unordered_map<string, int> mp;
			for(int j = 0; j < n; j++) {
				// 5-10位是考试日期，考试日期相符的学生 
				if(v[j].id.substr(4, 6) == request) {
					isEmpty = false;
					// temp 为准考证上的考场编号,用map记录考场编号与人数的映射，再用vector存储排序输出 
					string temp = v[j].id.substr(1, 3);
					mp[temp]++;
				}
			}
			for (auto it : mp)
				c.push_back({it.first, it.second});
			sort(c.begin(), c.end(), cmp3);
			for(int j = 0; j < c.size(); j++)
				printf("%s %d\n", c[j].testRoom.c_str(), c[j].people); 
		}
		if(isEmpty)
			printf("NA\n"); 
	}
	return 0;
}
