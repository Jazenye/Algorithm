#include <iostream> 
#include <cstdio>

using namespace std;

int main(){ 
    string password, input;
    int timesOfTry, i;
    cin >> password >> timesOfTry;
    
    getchar();
    for(i = 0; i < timesOfTry; i++) {
    	getline(cin, input); 
    	if(input == "#") return 0;
    	if(input == password){
    		cout << "Welcome in";
    		return 0;
		}
    	else
    		cout << "Wrong password: " << input << endl;
	}
	
	if(i == timesOfTry)
		cout << "Account locked";
    
	return 0;
}

