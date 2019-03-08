#include <iostream>
#include <unordered_map> 

using namespace std;

int main(){ 
    int m, n, s, no = 0, temp = 0; // no记录中奖了的人数 
    string nickname;
    cin >> m >> n >> s;

    // 用map记录中奖用户
    // s为起始中奖编号，n为中奖间隔，temp用来记录跳过的人数 
    unordered_map<string, int> user;
    for(int i = 1; i <= m; i++) { 
        cin >> nickname; 
        if(i == s + no * n + temp) {
            if(user.find(nickname) == user.end()) {
                // 没中过奖的入库
                user[nickname] = 1;
                cout << nickname << endl;
                no++;
            } else {
                temp++;
            }
        }
    }
    
    if(no == 0) cout << "Keep going..." ;
    return 0;
}
