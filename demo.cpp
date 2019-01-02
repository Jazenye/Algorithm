#include <iostream>
#include <cstdio>   //freopen function
#include <algorithm>

using namespace std;

#define MAXSIZE 105
bool cmp(int x, int y){
	return x>y;
}
int ary[MAXSIZE];
int main()
{
    int n = 8;

	//改变输出、输出流的文件指针: stdout/stdin 标准输出/输入流的文件指针
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

	while(scanf("%d", ary) != EOF)  //  常用重复输入,注意scanf是有返回值的
	{
	    for(int i=0; i<n; ++i)
            scanf("%d", &ary[i]);
	}

	sort(ary, ary+n); // 升序, 参数分别为起始地址与结束地址
//	sort(ary, ary+n, cmp); // cmp返回false时为降序排列
    for(int i=0; i<n; ++i)
    	cout<<ary[i]<<" ";

	return 0;
}
