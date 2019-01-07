#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct student{
	string name;
	string num;
	int score;
}student;

// 定义排序规则， > 表示从大往小排
bool compare(student a, student b){
	return a.score > b.score;
}

student stu[10001];
int main(){
	int n ;

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> stu[i].name;
		cin >> stu[i].num;
		cin >> stu[i].score;
	}

	sort(stu, stu+n, compare);   // <algorithm>
	cout << stu[0].name << " " << stu[0].num << endl;
	cout << stu[n-1].name << " " << stu[n-1].num;

	return 0;
}

//
//int main() {
//    int n, max = -1, min = 101, score;
//    cin >> n;
//    string maxname, minname, maxnum, minnum, name, num;
//    for (int i = 0; i < n; i++) {
//        cin >> name >> num >> score;
//        if (max < score) {
//            max = score;
//            maxname = name;
//            maxnum = num;
//        }
//        if (min > score) {
//            min = score;
//            minname = name;
//            minnum = num;
//        }
//    }
//    cout << maxname << " " << maxnum << endl << minname << " " << minnum;
//    return 0;
//}
