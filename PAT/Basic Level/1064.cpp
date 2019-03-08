#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int main(){ 
    int n, cnt = 0, num, friendID;
    set<int> s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        friendID = 0;
        cin >> num;
        while(num != 0) {
            friendID += num % 10;
            num /= 10;
        }
        s.insert(friendID);
    }
    cout << s.size() << endl;
    for(auto it = s.begin(); it != s.end(); it++) {
        if(it != s.begin()) cout << " ";
        cout << *it;
    }

	return 0;
}

