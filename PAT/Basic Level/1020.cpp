#include <iostream>      
#include <vector> 
#include <algorithm> 
using namespace std;  


// 定义降序排列，unit 表示单价，单价高的结构体排在前面
typedef struct mooncake{
	float count, sale, unit;
}mooncake;

bool cmp(mooncake a, mooncake b){
	return a.unit > b.unit;
}
int main() {  
	int n, need ;
	float sum = 0;
	scanf("%d%d", &n, &need); 
	
	vector<mooncake> v(n);
	for(int i=0; i<n; i++) scanf("%f", &v[i].count);  
	for(int i=0; i<n; i++){
		scanf("%f", &v[i].sale);    
		v[i].unit = v[i].sale / v[i].count; 
	}
	
	sort(v.begin(), v.end(), cmp);
	// 从单价高的开始取货，如果货量（count）不够则继续向后取
	for(int i=0; i<n; i++){
		if(v[i].count <= need){
			need -= v[i].count;
			sum += v[i].sale; 
		}
		else{
			sum += v[i].unit * need;
			break;
		}
	}
	printf("%.2f", sum); 
    	return 0;
} 

