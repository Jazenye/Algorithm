#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> score(m);
    vector<int> answer(m);
    vector<int> stuSum(m);
    for(int i = 0; i < m; i++)
        cin >> score[i];
    for(int i = 0; i < m; i++)
        cin >> answer[i];

    // 开始计算第 i 个学生 第j道题的得分情况
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int ans;
            cin >> ans;
            if(ans == answer[j])
                stuSum[i] += score[j];
        }
    }

    for(int i = 0; i < n; i++) {
        cout << stuSum[i];
        if(i != n - 1) cout << endl;
    }

	return 0;
}

