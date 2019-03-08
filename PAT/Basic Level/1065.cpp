#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main(){
    int n, m, male, female, cnt = 0;
    cin >> n;
    map<int, int> couple;
    for(int i = 0; i < n; i++) {
        cin >> male >> female;
        couple[male] = female;
        couple[female] = male;
    }

	cin >> m; 
    for(int i = 0; i < m; i++) {
        cin >> male;
	// 查看键是否存在，若不存在 肯定是单身旅客
	// 有伴侣的人则实现双向绑定，若对方的ID不是自己则说明他来了。
        if(couple.find(male) != couple.end()) {
        	// 如果他伴侣的值指向自己，则说明伴侣没来，把自己改为 -2，视为伴侣未到场
        	// 如果伴侣的值是-2， 代表伴侣已经来了，则把伴侣的值修改回来 
        	if(male == couple[couple[male]]) {
        		couple[male] = -2;
        		cnt++;
			}
        	else if(couple[couple[male]] == -2) {
        		couple[couple[male]] = male;
        		cnt--;
			}
		}
       	else{
       		couple[male] = -1;
       		cnt++;
		}
    }
	
    printf("%d\n", cnt);
    	
    bool isFirst = true;
    for(auto it = couple.begin(); it != couple.end(); it++) {
        if(it->second == -1 || it->second == -2) {
        	// 不是第一个输出,则在前面加空格 
        	if(!isFirst) printf(" ");
        	printf("%05d", it->first); 
            isFirst = false;
        }
    }

	return 0;
}

