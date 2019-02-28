#include <stdio.h>
#include <cstdio>

using namespace std;
//算法思想:
/*
1. 设立一个基准年月日（如0000年1月1日），计算两个年份到这个日期的天数差
2. 设立一个计数器，从该日开始计数，计算之后每一天到改日的具体天数差
  之后利用年份来查询（数组记录）
3. 设立一个计算天数差的函数于结构体内，以便在计算天数的时候日期会自动增加
4. 利用哈希思想，利用三维数组分别存储年月日，并用特定的输入技巧分割长串数字符
*/



// 判断闰年：能被4整除但不能被100整除 或者能被400整除，是闰年则返回1
// 有时候隔了8年才有闰年 如1896与1904
int isLeapyear(int x){
	if((x%100!=0 && x%4==0) || (x%400==0)) return 1;
	else return 0;
}

// 预存每个月份的天数，2月份有闰年之分
int dayOfMonth[13][2] = {
	0, 0,
	31, 31,
	28, 29,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31
};

// 日期的结构体数组
struct Date{
	int Year;
	int Month;
	int Day;
	// 计算当前日期下一天的日期
	void nextDay(){
		Day++;
		if(Day > dayOfMonth[Month][isLeapyear(Year)]){
			Day = 1;
			Month++;
			if(Month > 12){
				Month = 1;
				Year++;
			}
		}
	}
};

// 对于耗费大量内存的数组要定义在main外，或者使用malloc函数动态分配
int ary[5001][13][32];
// 计算绝对值函数
int abs(int x){
	return x>0?x:-x;
}

int main(){
//	freopen("in.txt", "r", stdin);
	int count = 0;
	Date tmp;
	tmp.Year = 0;
	tmp.Month = 1;
	tmp.Day = 1;

	// 计算某具体年份与0000年1月1日的天数差值，并保存在ary数组中
	while(tmp.Year != 5000){
		ary[tmp.Year][tmp.Month][tmp.Day] = count;
		tmp.nextDay();
		count++;
	}

	int y1,y2,m1,m2,d1,d2;
	// 注意如何获取输入
	while(scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF){
		scanf("%4d%2d%2d", &y2, &m2, &d2);
		int dif = abs(ary[y1][m1][d1] - ary[y2][m2][d2]) + 1;
		printf("%d", dif);
	}

	return 0;
}
