#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main(){ 
	int n, cnt = 0;
	char a[50], b[50];
	double temp, sum = 0.0;
	cin >> n;
	for(int i = 0; i < n; i++) {
        scanf("%s", a);
        // 不符合格式的不会输入到temp中，temp中不符合格式的也不会输出到b中
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f", temp);
//        cout << temp << "  " << b << endl;
        // 判断输出是否发生过改变，即若输入不合理的时候temp仍是上一次的取值
        // flag == 1表示此次为非法输入
        int flag = 0;
        for(int j = 0; j < strlen(a); j++) {
            if(a[j] != b[j])
                flag = 1;
        }

        if(flag == 1 || temp > 1000 || temp < -1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            // 变量sum 记录合法的浮点数总和，cnt记录合法的浮点数个数
            sum += temp;
            cnt++;
        }
	}

	if(cnt == 1)
        printf("The average of 1 number is %.2f", sum);
	else if(cnt == 0)
        printf("The average of 0 numbers is Undefined");
    else
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);

	return 0;
}

