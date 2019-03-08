#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct problem {
    int score, select, right = 0, wrong = 0, no;
    char answer[5];
};
bool cmp(problem a, problem b) {
    return a.wrong != b.wrong ? a.wrong > b.wrong : a.no < b.no;
}
int main(){
	int n, m;
	bool simple = true;
	cin >> n >> m;

    // v[m] 记录是第几道problem
    vector<problem> v(m);
	for(int i = 0; i < m; i++) {
        cin >> v[i].score >> v[i].select >> v[i].right;
        v[i].no = i + 1; //给题目上编号,方便后面排序
        for(int j = 0; j < v[i].right; j++)
             cin >> v[i].answer[j];
	}

    // 校验一下 输入的答案是否正确
//	for(int i = 0; i < m; i++) {
//        for(int j = 0; j < v[i].right; j++)
//            cout << v[i].answer[j] << " ";
//        cout << endl;
//	}

    // 计算每个学生的得分
	vector<int> sum(n);
	getchar(); // 获取一个换行符，不然后续用getline输入会少一行
	for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        // 第 i 个学生的第 j 道答题情况
        for(int j = 0; j < m; j++) {
            int temp = s.find(')');
            int temp2 = s.find('(') + 1;
            int num = s[temp2] - '0';
            int flag = 1;  // 若flag = 0 代表这题答错了

//            cout << num << " ";
            if(num != v[j].right)
                flag = 0;

            for(int k = 0; k < num && flag == 1; k++) {
                // an 记录第 i 个学生的第j道答题情况
                char an = s[temp2 + (k + 1) * 2];
//                cout << an << ":" << v[j].answer[k] << "  ";
                if(an != v[j].answer[k])
                    flag = 0;
            }
//            cout << " -- ";

            if(flag)
                sum[i] += v[j].score;
            else {
                v[j].wrong++;
                simple = false;
            }
            s.erase(0, temp + 1);
        }
//        cout << endl;
	}

	for(int i = 0; i < n; i++)
        cout << sum[i] << endl;
    if(simple){
        cout << "Too simple";
        return 0;
    }

    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < m; i++) {
        if(i + 1 < m && v[i].wrong == v[i+1].wrong) {
            continue;
        }
        cout << v[i].wrong << " ";
        for(int j = 0; j <= i; j++) {
            if(j != 0) cout << " ";
            cout << v[j].no;
        }
        break;

//      cout << v[i].no << ":" << v[i].wrong << endl;
    }

	return 0;
}

