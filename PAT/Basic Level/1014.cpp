#include <iostream>
#include <string>
using namespace std;

string week[7] = {
	"MON",
	"TUE",
	"WED",
	"THU",
	"FRI",
	"SAT",
	"SUN"
};
int main() {
	string str1, str2;
	string str3, str4;
	int flag = 0 ;
	cin >> str1 >> str2;

	// 处理str1 与 str2
	// 利用flag 来确定是处理第几次数据，当对比超过两次后需要结束本次对比
	for(int i=0; i<str1.length() && i<str2.length(); i++){
		if(str1[i] == str2[i]){
			if(flag == 0 && str1[i] >= 'A' && str1[i] <= 'G'){
				flag = 1;
				// 利用A的ASCII码为65
				int weekday = (int)str1[i] - 65;
				cout << week[weekday] << " ";
			}
			else if(flag == 1){
				if(str1[i] >= '0' && str1[i] <= '9'){
					flag = 2;
					cout << 0 << str1[i] << ":";    //  注意这个0是要的
				}

				else if(str1[i] >= 'A' && str1[i] <= 'N'){
					flag = 2;
					int num = (int)str1[i] - 65 + 10;
					cout << num << ":";
				}
				else if(flag == 2)
					break;
				else{
					continue;
				}
			}
		}
	}

	// 处理3和4行字符串，注意找到第一个相对应的大小写字母的位置即停止
	cin >> str3 >> str4;
	for(int i=0; i<str3.length() && i<str4.length(); i++){
		if(str3[i] == str4[i] && ((str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z') )){
			if(i > 9)
				cout << i;
			else
				cout << 0 << i;
			break;
		}
	}

    return 0;
}



// 按照题目所给的方法找到相等的字符后判断即可
// 如果输出的时间不足2位数要在前面添0，即用%02d输出
//#include <iostream>
//#include <cctype>
//using namespace std;
//int main() {
//    string a, b, c, d;
//    cin >> a >> b >> c >> d;
//    char t[2];
//    int pos, i = 0, j = 0;
//    while(i < a.length() && i < b.length()) {
//        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
//            t[0] = a[i];
//            break;
//        }
//        i++;
//    }
//    i = i + 1;
//    while (i < a.length() && i < b.length()) {
//        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i]))) {
//            t[1] = a[i];
//            break;
//        }
//        i++;
//    }
//    while (j < c.length() && j < d.length()) {
//        if (c[j] == d[j] && isalpha(c[j])) {
//            pos = j;
//            break;
//        }
//        j++;
//    }
//    string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
//    int m = isdigit(t[1]) ? t[1] - '0' : t[1] - 'A' + 10;
//    cout << week[t[0]-'A'];
//    printf("%02d:%02d", m, pos);
//    return 0;
//}

