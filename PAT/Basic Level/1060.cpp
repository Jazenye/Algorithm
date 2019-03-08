#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}
int a[100010];
int main(){ 
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    // 从下标1的地方开始存，降序排列
    sort(a+1, a+n+1, cmp1);
    int ans = 0, p = 1;
    while(ans <= n && a[p] > p) {
        ans++;
        p++;
    }
    printf("%d", ans);
	return 0;
}

