#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;
/*
算法思想:
1. 得知今天是周几
2. 计算与给定日期的天数差，具体星期 
*/



// 判断闰年：能被4整除但不能被100整除 或者能被400整除
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

// 星期几需要使用二维数组 ，同时注意从周几开始与设定的计算日期有关 
char weekname[7][20] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesay",
	"Thursday",
	"Friday",
	"Saturday"
	
};

char monthName[13][20] = {
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"Deceber"
};

// 结构体数组
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

int ary[5001][13][32];
int main(){
	freopen("in.txt", "r", stdin);
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

	int day, year, i;
	char month[20];
	while(scanf("%d%s%d", &day, month, &year) != EOF){  
		for(i=1; i<=12; ++i){
			// 比较两个字符串 若相等 则返回0 
			if(strcmp(monthName[i], month) == 0){ 
				break;
			} 
		}
		
		int days =  ary[year][i][day] - ary[2019][1][7];  
//		cout<<days<<"\n";
		printf("%s\n", weekname[(days%7+7)%7]);
//		printf("%s\n", weekname[days%7]);		
	}

	return 0;
}

