#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int ans[3001];
    fill(ans, ans + 3001, -1);
    for(int i = 1; i <= 3000; i++) {
        for(int j = 1; j <= 3000 - i - 1; j++) {
            int k2 = i * i + j * j;
            double s_k = sqrt(k2);
            if(floor(s_k) == s_k) {
                int k = floor(s_k), tar = i + j + k;
                if(tar > 0 && tar <= 3000) {
                    ans[tar] = max(ans[tar], i * j * k);
                }
            }
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}
