#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int n = str.length();
	int i,j;
	for(i=0;i<n/2;i++){
		if(str[i]!=str[n-1-i])
			break;
	}
	if(i == n / 2)  cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
} 
