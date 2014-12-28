#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<long long> f;
    f.push_back(1);
    f.push_back(2);
    long long up = 4 * 1e16;
    while(1) {
        if(*(f.rbegin()) + *(f.rbegin() + 1) <= up) {
            f.push_back(*(f.rbegin()) + *(f.rbegin() + 1));
        }else {
            break;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long ans = 0;
        for(size_t i = 0; i < f.size(); i++) {
            if(f[i] <= n && f[i] % 2ll == 0) {
                ans += f[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}

