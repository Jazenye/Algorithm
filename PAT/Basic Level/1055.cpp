#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct node {
    string name;
    int height;
};
bool cmp(node a, node b) {
    return a.height != b.height ? a.height > b.height : a.name < b.name;
}
int main(){
	// m为正常的每列人数， left为第一行的人数（因为面对拍照者，就是实际的最后一排）
    int n, k, m, left;
    cin >> n >> k;
    m = n / k;
    left = n % k + m;
//    cout << m << " " << left << endl;

    // que二维数组用来存放最终的排序结果， v用来存放输入数据
    vector<vector<string> > que(k, vector<string>(left, "aa"));
    vector<node> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].name >> v[i].height;
    sort(v.begin(), v.end(), cmp);

//    for(int i = 0; i < n; i++)
//        cout << v[i].name << " : " << v[i].height << endl;

    // 横排的坐标变化可以以中心轴看作一个数列， 0  -1  +1  -2  +2...
    int cnt = 0;
    for(int i = 0; i < k; i++){
        int centre = i == 0 ? (left / 2 + 1) : (m / 2 + 1);
        int row = i == 0 ? left : m;
        int p = 0;
        for(int j = 0; j < row && cnt < n; j++) {
            if(j % 2 == 1) p++;
            // temp 是一个规律数列，但放到数组中需要下标再减 1
            int temp = centre + pow(-1, j) * p;
            que[i][temp - 1] = v[cnt++].name;
        }
        for(int j = 0; j < row; j++) {
            if(j != 0) cout << " ";
            cout << que[i][j];
        }
        if(i != k - 1) cout << endl;
    }
	return 0;
}

