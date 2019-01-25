#include <iostream>   
using namespace std;    

int main() {  
	// 先算出有多少行，与多少个多余，再根据格式打印
	int n, line = 1, left = 0;
	char ch; 
	cin >> n >> ch;
	
	// n 是总个数，减去1后上下对称，并且从只有一个符号的那行开始计数符合规律： 2*line+1
	// 而当 n == 1时上下无元素，属于特殊情况故先 --，并此时默认只有一行元素
	n--; 
	while(n > 0){ 
		n = n - 2*(line*2+1); 
		line++;    // 根据规律从总数当中减，计算行数：line = （总行数+1）/2，另外一半对称打印即可
	} 
	// 当n ！= 0时代表多计算了一次（n=0时行数正好）,多计算的那次多出来的数就是剩余的数字
	if(n != 0){
		line--;    
		left = n + 2*(line*2+1); 
	}  
	

	// 只用打印前半部分的空格： 空格数 = 总行数 - 当前行数
	for(int i = line; i >= 1; i--){
		for(int j=0; j<line-i; j++) cout << " ";
		for(int j=0; j<(2*i-1); j++) cout << ch; 
		cout << endl;
	}
	for(int i=2; i <= line; i++){
		for(int j=0; j<line-i; j++) cout << " ";
		for(int j=0; j<(2*i-1); j++) cout << ch; 
		cout << endl;
	}
	
	cout << left; 
	return 0;
} 

 
