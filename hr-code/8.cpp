#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string input;
        cin >> input;
        int ans = 0;
        for(int j = 0; j < n; j++) {
            if(j + k > n) break;
            int cur = 1;
            for(int i = 0; i < k; i++) {
                cur *= (input[j+i] - '0');
            }
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}
