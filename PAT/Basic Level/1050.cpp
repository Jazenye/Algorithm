#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}
int main(){ 
	int sum, m, n, diff;
	cin >> sum;
	
	vector<int> v(sum);
	for(int i = 0; i < sum; i++)
        cin >> v[i];
    	sort(v.begin(), v.end(), cmp); 

	// 计算m,n ：diff 记录两者的差值,  i 代表m可能取值， sum / i 代表n可能取值 
    	diff = sum;
    	for(int i = sum; i > 0; i--){
    	// 要求 m >= n， 否则直接退出循环 
        if(i < sum / i)
            break;

		// 要求被整除，且两者差值最小， 即diff取到最小值 
        if((sum % i == 0) && (diff > (i - sum / i))){
            m = i;
            n = sum / m;  
            diff = m - n;
        }
        else
            continue;
    }

	// 用vector开一个二维数组, 并用K来记录填充到第几个元素了 
	vector< vector<int> > ary(m, vector<int>(n));
	int level = m / 2 + m % 2;
	int k = 0;
	for(int i = 0; i < level; i++) {
		// 第一个横向循环 → 
		for(int j = i; j < n - i && k < sum; j++) 
			ary[i][j] = v[k++];
		// 第一个纵向循环 ↓ 
		for(int j = i + 1; j < m - i - 1 && k < sum; j++)
			ary[j][n - i - 1] = v[k++];
		// 第二个横向循环 ←
		for(int j = n - i - 1; j >= i && k < sum; j--)
			ary[m - i - 1][j] = v[k++];
		// 第二个纵向循环 ↑ 
		for(int j = m - i - 2; j > i && k < sum; j--)
			ary[j][i] = v[k++]; 
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(j != 0)
				cout << " ";
			cout << ary[i][j]; 
		}
		cout << endl;
	}
	
	return 0;
}

