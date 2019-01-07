#include <iostream> 
#include <vector>
#include <algorithm>
 
using namespace std; 

int main() { 
 
	int n, m;
	cin >> n;
	cin >> m;
	
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];

	// m可能大于 n， 此时需要处理一下，避免不要的移动 
	m = m % n;
	if( m != 0){
		// 先转置两个子部分，再转置整体
		// reverse()  - > #include <algorithm>
		reverse(v.begin(), v.end()-m);
		reverse(v.end()-m, v.end());
		reverse(v.begin(), v.end());
	}
	
	for(int i=0; i<n; i++){
		if(i != 0) cout << " ";
		cout << v[i];
	}

    return 0;
}
