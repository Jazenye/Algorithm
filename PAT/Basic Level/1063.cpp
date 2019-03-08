#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    int n, real, img;
    double r = 0, maxR = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> real >> img;
        r = sqrt(double(real * real + img * img));
        if(maxR < r)
            maxR = r;
    }

    printf("%.2f", maxR);
	return 0;
}

