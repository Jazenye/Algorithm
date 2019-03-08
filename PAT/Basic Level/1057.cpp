#include <iostream>
#include <cctype>
#include <string>
#include <cstdio>

using namespace std;

int main(){
	string s, bin;
	int sum = 0, sumOfZero = 0, sumOfOne = 0;
	// 可能含空格 故用Getline
	getline(cin, s);
	// 都转化为大写，大写A的ascii码为65，所以各个字母转为大写后-64即得权重
	for(int i = 0; i < s.length(); i++)
        if(isalpha(s[i]))
            sum += toupper(s[i]) - 64;

    // 进制转换
    while(sum != 0){
        bin += to_string(sum % 2);
        sum /= 2;
    }

    for(int i = 0; i < bin.length(); i++)
        bin[i] == '1' ? sumOfOne++ : sumOfZero++;

    cout << sumOfZero << " " << sumOfOne;
	return 0;
}

