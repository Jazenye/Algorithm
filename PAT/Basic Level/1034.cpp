#include <iostream>
#include <cmath> 

using namespace std;
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
void simplify(long long a, long long b) {
    if(a * b == 0) {
        printf("%s", b == 0 ? "Inf" : "0");
        return;
    }
    // 判断是否为负数， 若未负数则flag == 1 , 且需要增加括号
    // 不能用运算判断大小， 容易溢出
    int flag = 0;
    if( (a < 0 && b > 0) || (a > 0 && b < 0))
        flag = 1;

    // 避免符号带来的影响
    a = abs(a);
    b = abs(b);
    long long k = a / b; // K 为假分数多出来的部分

    // 接下来根据 有无负号以及假分数进行打印
    printf("%s", flag == 1 ? "(-" : "");
    if(k != 0) printf("%lld", k);
    // K 后没有分数，则可以结束打印，若还有数字，则需要进一步判断
    if(a % b == 0) {
        if(flag)
            printf(")");
        return;
    }
    if(k != 0) printf(" ");
    a = a - k * b;
    long long temp = gcd(a, b);
    a = a / temp;
    b = b / temp;
    printf("%lld/%lld%s", a, b, flag == 1 ? ")":"");
}

long long int a, b, c, d;
int main(){ 
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    simplify(a, b); printf(" + "); simplify(c, d); printf(" = "); simplify(a * d + b * c, b * d); printf("\n");
    simplify(a, b); printf(" - "); simplify(c, d); printf(" = "); simplify(a * d - b * c, b * d); printf("\n");
    simplify(a, b); printf(" * "); simplify(c, d); printf(" = "); simplify(a * c, b * d); printf("\n");
    simplify(a, b); printf(" / "); simplify(c, d); printf(" = "); simplify(a * d, b * c);
    return 0;
}
