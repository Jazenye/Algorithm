#include <iostream>  
#include <cctype>
#include <unordered_map>
#include <vector>
#include <algorithm> 

using namespace std;
//double score 用来存储加权总成绩， 之后再转换为int sum来取整存储 
struct rankList {
	string name;
	int num = 0, sum;
	double score;
};
bool cmp(rankList a, rankList b) {
	if(a.sum != b.sum) return a.sum > b.sum;
	else if(a.num != b.num) return a.num < b.num;
	else return a.name < b.name;
}
int main() { 
	int n; cin >> n;
	int cnt = 0, temp; 
	unordered_map<string, int> mp;
	vector<rankList> v(n);
	for(int i = 0; i < n; i++) {
		string id, school; double score;
		cin >> id >> score >> school;
		// 学校改成小写 
		for(int j = 0; j < school.length(); j++)  
			school[j] = tolower(school[j]);
		// map中存放学校名称在vector中下的下标 ,判断条件是学校名没在map中出现过 
		if(mp.count(school) == 0)  
			mp[school] = cnt++; 
		if(id[0] == 'T') score *= 1.5;
		else if(id[0] == 'B') score /= 1.5;	 
		v[mp[school]].name = school;
		v[mp[school]].score += score;   // 先处理成绩的权值，再加上 
		v[mp[school]].num++;    // 统计该校参赛人数  
	}
	v.resize(cnt); 
	// double类型的成绩转换为 int存储起来 
	for(int i = 0; i < cnt; i++)  
		v[i].sum = (int)v[i].score; 
	sort(v.begin(), v.end(), cmp);
	int rank = 1;
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++) {
		if(i != 0 && v[i].sum != v[i - 1].sum) 
			rank = i + 1; 
		printf("%d %s %d %d\n", rank, v[i].name.c_str(), v[i].sum, v[i].num);
	}
	return 0;
}
