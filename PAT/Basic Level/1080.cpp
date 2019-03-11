#include <iostream> 
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

struct stu {
	string name;
	int program, midterm, final, g;
};
bool cmp(stu a, stu b) {
	return a.g != b.g ? a.g > b.g : a.name < b.name;
}
int main() { 
	int homework, middle, final, score, cnt = 0;
	string name;
	map<string, int> mp;  // 用map存储在数组中的下标，减少时间复杂度 
	scanf("%d %d %d", &homework, &middle, &final); 
	vector<stu> v;
	
	// 前面三个for循环就是处理输入，时间复杂度要尽量低，否则易超时 
	// 用C语言输入的string类型好像无法比较 
	for(int i = 0; i < homework; i++) {
		cin >> name >> score;
		if(score >= 200) {
			mp[name] = cnt++; 
			v.push_back(stu{name, score, -1, -1, 0});
		}
	}
	int len = v.size(); 
	for(int i = 0; i < middle; i++) {
		cin >> name >> score; 
		if(mp.count(name) != 0)
			v[mp[name]].midterm = score;
	}
	for(int i = 0; i < final; i++) { 
		cin >> name >> score;
		if(mp.count(name) != 0)
			v[mp[name]].final = score;
	}
	
	// 计算最终成绩并排序， 注意要四舍五入 
	for(int i = 0; i < len; i++) {
		if(v[i].midterm > v[i].final)
			v[i].g = (int)(v[i].midterm * 0.4 + v[i].final * 0.6 + 0.5);
		else 
			v[i].g = v[i].final;
	}
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < len; i++) {
		if(v[i].g < 60)
			break;
		printf("%s %d %d %d %d\n", v[i].name.c_str(), v[i].program, v[i].midterm, v[i].final, v[i].g);
	}
	
	return 0;
}
