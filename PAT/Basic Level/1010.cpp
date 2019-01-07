#include <iostream>   
#include <cstdio>
using namespace std; 

int ary[10001];
int main() { 

	freopen("in.txt", "r", stdin);
	int i=0, flag = 0; 
	
	while(cin >> ary[i])
		i++;
	i--; 

 	// 设置flag ,flag = 1表示前面已经有字符输出 
	for(int j=0; j<=i; j+=2){
		if(ary[j+1] != 0){ 
			// 注意加空格这句话应当是确保前面已经有字符输出时才可以用
			// 当j != 0 时不一定能保证前面已经有字符输出了，因为首项可能是常数项无字符输出 
			if( flag == 1) cout << " ";  
			else flag = 1;
			cout << ary[j] * ary[j+1] << " ";
			cout << ary[j+1] - 1;
		}	
	}
	
	// 若从未改变 则输出 0 0，代表其它项均为0  
	if(flag == 0) cout << "0 0";
	
    return 0;
}


//    也可以边输入边处理，更加简洁 
//    int a, b, flag = 0;
//    while (cin >> a >> b) {
//        if (b != 0) {
//            if (flag == 1) cout << " ";
//            cout << a * b << " " << b - 1;
//            flag = 1;
//        }
//    }
//    if (flag == 0) cout << "0 0";

