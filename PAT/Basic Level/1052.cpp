#include <iostream>   
#include <string>   
using namespace std;    

void selectCh(string ary, int &cnt, string ch[]){
	int start, len = ary.length(); 
	for(int i = 0; i < len; i++){
		if(ary[i] == '['){
			start = i + 1; 
			while(ary[i] != ']' && i < len) i++;
			if(i < len ) ch[cnt++] = ary.substr(start, i - start); 
		}
	}
};
int main() {  
	string hand, eye, mouse;
	string h[11], e[11], m[11];
	getline(cin, hand);
	getline(cin, eye);
	getline(cin, mouse);
	
	int cnth = 0, cnte = 0, cntm = 0;
	selectCh(hand, cnth, h);
	selectCh(eye, cnte, e);
	selectCh(mouse, cntm, m);

	
	int n, lhand, leye, inmouse, reye, rhand;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> lhand >> leye >> inmouse >> reye >> rhand; 
		if(lhand > cnth || leye > cnte || inmouse > cntm || reye > cnte || rhand > cnth || lhand < 1 || leye < 1|| inmouse < 1 || reye < 1 || rhand < 1){
			cout << "Are you kidding me? @\\/@" << endl; 
		} else {
			cout << h[lhand-1] << "(" << e[leye-1] << m[inmouse-1] << e[reye-1]<< ")" << h[rhand-1] << endl;
		}
	} 
	
	return 0;
} 

 
