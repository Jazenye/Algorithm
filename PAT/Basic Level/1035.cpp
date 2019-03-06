#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 105;
int A[N], B[N], C[N], n; // 三个数组，A存放再排序一次后，B、C分别存放初始数据，并用于存放排序过程

// 判断两个数组是否相同, 相同则返回true
bool isSame(int A[], int B[]){
	for(int i = 0; i < n; i++){
		if(A[i] != B[i])
            return false;
	}
	return true;
}

// 排序依次后， 打印该数组
bool showArray(int A[]){
	for(int i = 0; i < n; i++){
		printf("%d", A[i]);
		if(i < n - 1)
            printf(" ");
	}
	printf("\n");
}

// 插入排序过程
bool insertSort(){
	bool flag = false;
	for(int i = 1; i < n; i++){
		if(i != 1 && isSame(B, C))
			flag = true;

		// 完成第 i 次插入排序过程， 至少完成一次插入排序方可开始比较
		// 每次比较的是第 i - 1 次的插入排序结果
		int temp = B[i], j = i;
		while(j > 0 && B[j - 1] > temp){
			B[j] = B[j - 1];
			j--;
		}
		B[j] = temp;

		if(flag == true)
			return true;
	}
	return false;
}

// 归并排序过程
void mergeSort(){
	bool flag = false;
	for(int step = 2; step / 2 <= n; step *= 2){
		if(step != 2 && isSame(B, C))
			flag = true;
        // 完成一次归并排序 后进行比较
		for(int i = 0; i < n; i += step)
			sort(B + i, B + min(i + step, n));
		if(flag == true){
			showArray(B);
			return;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &A[i]);
		B[i] = A[i];
	}
	for(int i = 0; i < n; i++)
		scanf("%d", &C[i]);

    // 判断是否是插入排序， 如果不是则执行归并排序过程，并进行比较究竟是哪一次归并排序
	if(insertSort()){
		printf("Insertion Sort\n");
		showArray(B);
	} else {
		printf("Merge Sort\n");
		for(int i = 0; i < n; i++){
			B[i] = A[i];
		}
		mergeSort();
	}
	return 0;
}

