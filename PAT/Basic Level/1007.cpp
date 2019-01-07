#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int n, count = 1, flag = 0, tmp1, tmp2;

	cin >> n;
	vector<int> v(n+1);  // 最好开n+1个空间 避免越界

	// 注意要return 0 ， 提前返回
	// n <= 3时是特殊情况需要另外判断
	// n=5的时候是1, n=7时为2
	if(n == 1 || n == 2 || n == 3){
		cout << 0;
		return 0;
	}

	for(int i=4; i<=n; i++){
		// 判断 从0-i 哪些是素数，不是素数的记为1
		for(int j=2; j<=sqrt(i); j++){
			if(i%j == 0){
				v[i] = 1;
				break;
			}
		}
	}


	// 寻找剩下的素数对
	// flag=0 代表是素数对的第一个数
	// 存储两个相邻的素数为tmp1 与 tmp2
	// 当它们差值不为2的时候，将tmp2的值赋给tmp1 然后寻找下一个素数给tmp2
	for(int i=4; i<=n; i++){
		if(v[i] == 0){   //  i为素数
			if(flag == 0){
				flag = 1;
				tmp1 = i;
			}
			else{
				flag = 0;
				tmp2 = i;
			}

			// 相邻素数确定完毕时 flag=0，此时在进行判断
			if(flag == 0){
				if(tmp2 - tmp1 == 2)
					count++;
				else {
					flag = 1;
					tmp1 = tmp2;
				}
			}
		}
	}

	cout << count;

    return 0;
}



//bool isprime(int a) {
//    for (int i = 2; i * i <= a; i++)
//        if (a % i == 0) return false;
//    return true;
//}
//int main() {
//    int N, cnt = 0;
//    cin >> N;
//    for (int i = 5; i <= N; i++)
//        if (isprime(i-2) && isprime(i)) cnt++;
//    cout << cnt;
//    return 0;
//}
