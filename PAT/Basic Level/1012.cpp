#include <iostream>   
#include <vector>
#include <math.h>
#include <cstdio>
using namespace std; 

int main() { 

	freopen("in.txt", "r", stdin);
	
	int n, tmp, flag = 0;
	scanf("%d", &n);
	
	vector<int> v(n);
	for(int i=0; i<n; i++){
		scanf("%d", &v[i]); 
	}
	
	
	for(int i=0; i<5; i++){
		if(i != 0) cout << " ";
		flag = 0;   // 注意每次循环结束后需要重置flag 
		if(i == 0){
			tmp = 0;
			for(int j=0; j<n; j++){ 
				if(v[j]%5==0 && v[j]%2==0){
					flag = 1;
					tmp += v[j];
				}
			} 
		}
		else if( i == 1){
			tmp = 0;
			int count = 0;
			for(int j=0; j<n; j++){ 
				if(v[j]%5 == 1){
					flag = 1;
					tmp += pow(-1, count)*v[j];
					count++;
				}
			}
		}
		else if( i == 2){
			tmp = 0;
			for(int j=0; j<n; j++){ 
				if(v[j]%5 == 2){
					flag = 1;
					tmp++;
				}
			} 
		}
		else if( i == 3){
			tmp = 0;
			int count = 0;
			double average;
			for(int j=0; j<n; j++){ 
				if(v[j]%5 == 3){
					flag = 1;
					count++;
					tmp += v[j];
				}
			}
			if(flag){
				average = (double)tmp/count;
				printf("%.1f", average);
				continue;
			}
		}
		else{ 
			for(int j=0; j<n; j++){ 
				if(v[j]%5 == 4){
					if(flag == 0) tmp = v[j];
					flag = 1;
					if(tmp < v[j]) tmp = v[j];
				}
			}
		}
		
		if(flag == 0)
			printf("N");
		else
			printf("%d", tmp);
	}
	
    return 0;
} 

