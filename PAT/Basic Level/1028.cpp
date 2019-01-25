#include <iostream>   
using namespace std;    

int main() { 
	freopen("in.txt", "r", stdin);
	int n, cnt = 0;
	string name, birth, maxname, minname;
	string maxbirth = "1814/09/06", minbirth = "2014/09/06";

	// maxbirth 最晚出生的人，即最年轻的人 
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> name >> birth;
		if(birth <= "2014/09/06" && birth >= "1814/09/06"){
			cnt++;
			if(birth >= maxbirth){
				maxbirth = birth;
				maxname = name;
			}
			if(birth <= minbirth){
				minbirth = birth;
				minname = name;
			}
		}
	}
	
	cout << cnt;
	if (cnt != 0)  cout << " " << minname << " " << maxname;
	return 0;
} 

 
