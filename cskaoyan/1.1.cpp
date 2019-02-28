#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <string.h>

using namespace std;

struct student{
	char name[101];
	int age;
	int score;
	// 定义结构体的 小于 运算符
//	bool operator < (const student &b) const{
//		if(score != b.score) return score < b.score;
//		int tmp = strcmp(name, b.name);
//		if(tmp) return tmp < 0;
//		else return age < b.age;
//	}
}ary[1000];

//定义排序规则
bool cmp(student a, student b){
	// 分数不同 则低分者在前
	if(a.score != b.score) return a.score < b.score;

	int tmp = strcmp(a.name, b.name);

	if(tmp) return tmp < 0;
	else return a.age < b.age;
}

int main(){
	int n;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while(scanf("%d", &n) != EOF){
		for(int i=0; i<n; ++i){
			scanf("%s%d%d", ary[i].name, &ary[i].age, &ary[i].score);
		}

		sort(ary, ary+n, cmp);
		// 重载运算符后的比较函数
//		sort(ary, ary+n);

		for(int i=0; i<n; ++i){
			printf("%s %d %d\n", ary[i].name, ary[i].age, ary[i].score);
		}
	}

	return 0;
}
