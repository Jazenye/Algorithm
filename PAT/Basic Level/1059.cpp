#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>

using namespace std;

bool isprime (int a) {
    for(int i = sqrt((double)a); i > 1; i--) {
        if(a % i == 0)
            return false;
    }
    return true;
}

int main(){ 
    int n, k, id;
    cin >> n;
//    vector<int> stuRank(n);
    map<int, string> stuRank;
    for(int i = 0; i < n; i++) {
        cin >> id;
        string s = "Chocolate";
        if(i == 0)
            s = "Mystery Award";
        else if(isprime(i + 1))
            s = "Minion";
        stuRank[id] = s;
//        cout << id << " " << s << endl;
    }

    // query
    cin >> k;
    for(int i = 0; i < k; i++) {
        string str;
        cin >> str;
        id = stoi(str);
        cout << str << ": ";
        if(stuRank.find(id) != stuRank.end()) {
            cout << stuRank[id];
            stuRank[id] = "Checked";
        } else {
            cout << "Are you kidding?";
        }
        if(i != k - 1) cout << endl;
    }

	return 0;
}

