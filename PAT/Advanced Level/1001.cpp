#include <iostream>   
#include <algorithm> 
#include <cmath>
using namespace std; 

int main() {
	int a, b, sum, isNagtive = 0, cnt = 0;
	string result;
	cin >> a >> b;
	sum = a + b;
	// 单独把负号拎出来，避免麻烦的判断 
	if(sum < 0)
		isNagtive = 1;
	result = to_string((int)fabs(sum));
	reverse(result.begin(), result.end());
	// 每三位数用一个逗号分隔（从后往前），故先转置后再用insert添加 
	// cnt用来计数已经添加的逗号个数
	// 因为每次插入都会改变字符串长度，故用cnt去纠正 
	int len = result.size();
	for(int i = 1; i < len + cnt - 1; i++) {
		if((i + 1 - cnt) % 3 == 0) {
			result.insert(i + 1, ",");
			cnt++; 
			i++;
		}
	}
	reverse(result.begin(), result.end());
	if(isNagtive)
		result = "-" + result;
	cout << result;
	return 0;
}
