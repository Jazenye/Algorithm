#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, p = 0, t = 0;
    string s;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> s;

        map<char, int> count;  // 用map容器来记录各个字符出现的次数,再用额外的pt变量来记录字符出现的位置

        for(int j = 0; j < s.size(); j++) {
            count[s[j]]++;
            // 找到字母PT在字符串中的位置
            if (s[j] == 'P') p = j;
            if (s[j] == 'T') t = j;
        }

        // 仅PAT三个字母，且PT各仅有一个，A>=1个
		// 用PT的位置分割出三部分A ,且注意对PT位置的判断
		// 开头A的个数（p的位置） *  中间A的个数（PT位置差-1） == T后A的个数(s长度-t的位置-1）
        if (count['P'] == 1 && count['A'] != 0 && count['T'] == 1 && count.size() == 3 && t-p > 1 && p * (t-p-1) == s.length()-t-1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
