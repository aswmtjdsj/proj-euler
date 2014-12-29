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
        int n;
        cin >> n;
        vector <vector<int> > input;
        input.resize(n);
        for(int i = 0; i < n; i++) {
            input[i].resize(i+1);
            for(int j = 0; j <= i; j++) {
                cin >> input[i][j];
            }
        }
        vector <vector<int> > dp = input;
        int ans;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                ans = dp[i][0];
                continue;
            }
            for(int j = 0; j <= i; j++) {
                if(j == 0) dp[i][j] = dp[i-1][j] + input[i][j];
                else if(j == i) dp[i][j] = dp[i-1][j-1] + input[i][j];
                else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + input[i][j];
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
