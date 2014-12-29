#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 501;
const int mod = 1000000007;
int dp[N][N];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == 0 && j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = dp[i][j-1];
            else if(j == 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << endl;
    }
    return 0;
}

