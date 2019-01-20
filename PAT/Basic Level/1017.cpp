#include <iostream>
using namespace std;

int main() {
	string a;
	int b, t, tmp, flag = 0;

	cin >> a >> b;

	if((a[0]-'0') == 0){
		cout << "0 0";
		return 0;
	}

	// flag = 1 代表下一次运算是两位数除一位数（需要借位）
	for(int i=0; i<a.length(); i++){
		t = a[i] - '0';
		if(flag == 0 && t / b == 0){
			// 此位不够除，故先输出一个0，再向低位借位形成一个新的两位数
			// 首位不够除时，直接借位 而不输出0
			if(i!= 0) cout << 0;
			if(t % b == 0)  continue;
			if((i+1) < a.length()){
				i++;
				t = t*10 + (a[i] - '0');
			}
		}
		//两位数运算，将上一位运算完的余数拿来组成新数字
		else if(flag == 1){
			t = t + (a[i-1]-'0')*10;
		}

		cout << t / b;

		// 运算完毕：若整除,flag 仍未0 下一位继续运算；
		// 未整除，则算出余数补回原位，令flag = 1
		if(t % b != 0){
			flag = 1;
			a[i] = (char)(t % b+48);  // 数字转字符：48是0的ASCII码
		}
		else
			flag = 0;
	}

	cout << " " << t % b;

    return 0;
}



// 模拟手动除法的过程，每次用第一位去除以B，如果得到的商不是0就输出，
// 否则就*10+下一位，直到最后的数为余数～
//int main() {
//    string s;
//    int a, t = 0, temp = 0;
//    cin >> s >> a;
//    int len = s.length();
//    t = (s[0] - '0') / a;
//    if ((t != 0 && len > 1) || len == 1)
//        cout << t;
//    temp = (s[0] - '0') % a;
//    for (int i = 1; i < len; i++) {
//        t = (temp * 10 + s[i] - '0') / a;
//        cout << t;
//        temp = (temp * 10 + s[i] - '0') % a;
//    }
//    cout << " " << temp;
//    return 0;
//}
