#include <iostream>
#include <algorithm>
#include <malloc.h>

using namespace std;
typedef struct student{
	int num;
	int score1;
	int score2;
}student;

// 定义排序规则：先按照总分排序，再按照品德分升序,若品德分也相同 则按照学号升序
bool cmp(student a, student b){
	if((a.score1+a.score2) != (b.score1+b.score2))  return (a.score1+a.score2) > (b.score1+b.score2);
	else if(a.score1 != b.score1)  return a.score1 > b.score1;
	else  return a.num < b.num;
}

// 思想：将四类人分到四个结构体数组中，分别排序然后依次输出
int main() {
	int n, l, h, count1, count2, count3, count4;
	count1 = count2 = count3 = count4 = 0;
	scanf("%d%d%d", &n, &l, &h);

    // 分成四类结构体... 这样分配内存消耗有些大，所以最好还是用vector 自动调节大小
	student *stu, *stu1, *stu2, *stu3, *stu4;
	stu = (student *)malloc(n*sizeof(student));
	stu1 = (student *)malloc(n*sizeof(student));
	stu2 = (student *)malloc(n*sizeof(student));
	stu3 = (student *)malloc(n*sizeof(student));
	stu4 = (student *)malloc(n*sizeof(student));

	// 根据题意指定的分类规则，主要注意几个等号是否取到的问题
	// 这里有许多重复赋值的操作十分不便
	for(int i=0; i<n; i++){
		scanf("%d%d%d", &stu[i].num, &stu[i].score1, &stu[i].score2);
		if(stu[i].score1 >= h && stu[i].score2 >= h){
			stu1[count1].num = stu[i].num;
			stu1[count1].score1 = stu[i].score1;
			stu1[count1].score2 = stu[i].score2;
			count1++;
		}
		else if(stu[i].score1 >= h && stu[i].score2 >= l){
			stu2[count2].num = stu[i].num;
			stu2[count2].score1 = stu[i].score1;
			stu2[count2].score2 = stu[i].score2;
			count2++;
		}
		else if(stu[i].score1 >= l && stu[i].score2 >= l && stu[i].score1 >= stu[i].score2){
			stu3[count3].num = stu[i].num;
			stu3[count3].score1 = stu[i].score1;
			stu3[count3].score2 = stu[i].score2;
			count3++;
		}
		else if(stu[i].score1 >= l && stu[i].score2 >= l){
			stu4[count4].num = stu[i].num;
			stu4[count4].score1 = stu[i].score1;
			stu4[count4].score2 = stu[i].score2;
			count4++;
		}
	}

	// 对四种类型分别进行排序
	sort(stu1, stu1+count1, cmp);
	sort(stu2, stu2+count2, cmp);
	sort(stu3, stu3+count3, cmp);
	sort(stu4, stu4+count4, cmp);

	int count = count1+count2+count3+count4;
	printf("%d", count);
	if(count) printf("\n");
	else return 0;   // 对于极端情况，无人及格时直接结束

	// 注意输出格式，换行符何时输出
	// if(counti .. ) 指的是当第一行前有发生过输出时，则额外输出一个换行符。
	for(int i=0; i<count1; i++){
		if(i != 0) printf("\n");
		printf("%d %d %d", stu1[i].num, stu1[i].score1, stu1[i].score2);
	}
	for(int i=0; i<count2; i++){
		if(count1 || i != 0) printf("\n");
		printf("%d %d %d", stu2[i].num, stu2[i].score1, stu2[i].score2);
	}
	for(int i=0; i<count3; i++){
		if(count1 || count2 || i != 0) printf("\n");
		printf("%d %d %d", stu3[i].num, stu3[i].score1, stu3[i].score2);
	}
	for(int i=0; i<count4; i++){
		if(count1 || count2 || count3 || i != 0) printf("\n");
		printf("%d %d %d", stu4[i].num, stu4[i].score1, stu4[i].score2);
	}

    return 0;
}


// 转自柳婼 她的方法确实很简洁
// 利用vector 设定结构体类型数组，节省了空间 并且自带方法无需再用动态分配及额外的count变量
// 总数按照不及格人数来计算，也算一种逆向的剪枝 值得学习
// 对vecotr进行遍历（4个结构体数组的容器），省去了许多重复操作

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//struct node {
//    int num, de, cai;
//};
//int cmp(struct node a, struct node b) {
//    if ((a.de + a.cai) != (b.de + b.cai))
//        return (a.de + a.cai) > (b.de + b.cai);
//    else if (a.de != b.de)
//        return a.de > b.de;
//    else
//        return a.num < b.num;
//}
//int main() {
//    int n, low, high;
//    scanf("%d %d %d", &n, &low, &high);
//    vector<node> v[4];
//    node temp;
//    int total = n;
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d %d", &temp.num, &temp.de, &temp.cai);
//        if (temp.de < low || temp.cai < low)
//            total--;
//        else if (temp.de >= high && temp.cai >= high)
//            v[0].push_back(temp);
//        else if (temp.de >= high && temp.cai < high)
//            v[1].push_back(temp);
//        else if (temp.de < high && temp.cai < high && temp.de >= temp.cai)
//            v[2].push_back(temp);
//        else
//            v[3].push_back(temp);
//    }
//    printf("%d\n", total);
//    for (int i = 0; i < 4; i++) {
//        sort(v[i].begin(), v[i].end(), cmp);
//        for (int j = 0; j < v[i].size(); j++)
//            printf("%d %d %d\n", v[i][j].num, v[i][j].de, v[i][j].cai);
//    }
//    return 0;
//}
