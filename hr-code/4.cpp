#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector <int> S;
    for(int i = 100; i < 1000; i++) {
        for(int j = i; j < 1000; j++) {
            int p = i * j;
            char biubiu[10];
            sprintf(biubiu, "%d", p);
            int l = strlen(biubiu);
            bool flag = true;
            for(int i = 0; i < l/2; i++) {
                if(biubiu[i] != biubiu[l-i-1]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                S.push_back(p);
            }
        }
    }
    sort(S.begin(), S.end());
    int t;
    cin >> t;
    while(t--) {
        int a;
        cin >> a;
        auto idx = lower_bound(S.begin(), S.end(), a);
        cout << *(idx-1) << endl;
    }
    return 0;
}
