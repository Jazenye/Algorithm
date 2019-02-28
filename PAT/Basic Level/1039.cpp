#include <iostream>
using namespace std;

int main() {
	string s1, s2;
	int flag = 0, cnt = 0;
	// 用getline 为了防止店家没珠子时 用Cin错误输入
	getline(cin, s1);
	getline(cin, s2);

	int len1 = s1.length();
	int len2 = s2.length();
	for(int i = 0; i < len2; i++){
		int k = s1.find(s2[i]);
		if(k == string::npos){
			flag = 1;  // flag = 1 表示缺珠子
			cnt++;
		} else {
			// 如果找到这颗珠子就从s1中去掉 避免漏算了cnt
			// 当做从店家买下了这颗珠子
			s1.erase(k, 1);
		}
	}

	if(flag == 1){
		cout << "No " << cnt;
	} else {
		cout << "Yes " << len1 - len2;
	}

	return 0;
}


//hash 思想,字符字母全都转换为数字
//int book[256];
//int main() {
//    string a, b;
//    int result = 0;
//    cin >> a >> b;
//    for (int i = 0; i < a.length(); i++)
//        book[a[i]]++;
//
//    for (int i = 0; i < b.length(); i++) {
//        if (book[b[i]] > 0)
//            book[b[i]]--;
//        else
//            result++;
//    }
//
//    if(result != 0)
//        printf("No %d", result);
//    else
//        printf("Yes %d", a.length() - b.length());
//    return 0;
//}


