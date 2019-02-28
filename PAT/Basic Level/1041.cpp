#include <iostream>
#include <vector>
using namespace std;

struct stu{
	string num;
	int test, exam;
};
int main() {
	int n, m, query;
	cin >> n;

	vector<stu> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].num >> v[i].test >> v[i].exam;
	}

	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> query;
		for(int j = 0; j < n; j++){
			if(query == v[j].test){
				cout << v[j].num << " " << v[j].exam << endl;
				break;
			}
		}
	}

	return 0;
}

//
//用二维数组解决此题
//int main() {
//  string stu[1005][2], s1, s2;;
//  int n, m, t;
//  cin >> n;
//  for(int i = 0; i < n; i++) {
//      cin >> s1 >> t >> s2;
//      stu[t][0] = s1;
//      stu[t][1] = s2;
//  }
//  cin >> m;
//  for(int i = 0; i < m; i++) {
//      cin >> t;
//      cout << stu[t][0] << " " << stu[t][1] << endl;
//  }
//  return 0;
//}
