#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

bool cmp(int a, int b){
	return a>b;
}

 // 记录被访问过的序列,若该数字被访问过则记为1 
 // 如果开1000大小数据会不够用 
int ary[10000]; 
int main() {
	int k, n;
	cin >> k;
	
	vector<int> num(k, 0);
	for(int i=0; i<k; i++){
		cin >> n;
		num[i] = n;
		while( n != 1){
			if( n%2 != 0) n = 3*n+1;
			n = n / 2;
			// 必要的break 用来剪枝可以稍微快一点 
//			if (ary[n] == 1) break;
			ary[n] = 1;
		}
	}
	
	// 将vector中的数据从大到小排列 
	// 对于第一个元素，一开始设为1，而后面不是第一个元素的时候设为0
	// 对于非首元素，则在输出前加空格 
	int isFirst = 1;  
	sort(num.begin(), num.end(), cmp);
	for(int i=0; i<num.size(); i++){
		if(ary[num[i]] == 0){
			if(!isFirst)  cout << " ";
			cout << num[i];
			isFirst = 0;
		}
	}
		
    return 0;
}
