#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int a, b, c, d, k;
    scanf("%d/%d %d/%d %d", &a, &b, &c, &d, &k);
    // 若前面的分数大 则交换
    if(a * d - b * c > 0) {
        swap(a, c);
        swap(b, d);
    }

    // 找到介于两个分数之间且不可被化简的分子
    vector<int> v(k);
    int cnt = 0;
    for(int i = 1; i < k; i++) {
        if((a * k - b * i < 0) && (c * k - d * i > 0) && (gcd(k, i) == 1)) {
            v[cnt++] = i;
        }
    }

    for(int i = 0; i < cnt; i++) {
        if(i != 0) cout << " ";
        cout << v[i] << "/" << k;
    }

	return 0;
}
