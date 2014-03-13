#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 200

int dp[N][N];
int a[N][N];
const int BB = 0x7f7f7f7f;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j!=n-1)
                scanf(" %d,", &a[i][j]);
            else
                scanf(" %d", &a[i][j]);
        }
    }
    memset(dp, BB, sizeof(dp));
    for(int i = 0; i < n; i++)
        dp[i][0] = a[i][0];
    for(int j = 1; j < n; j++) {
        for(int i = 0; i < n; i++) {
            dp[i][j] = dp[i][j-1] + a[i][j];
        }
        for(int i = 0; i < n; i++) {
            dp[i][j] = min(min(i>0?dp[i-1][j]:BB, i<n-1?dp[i+1][j]:BB) + a[i][j], dp[i][j]);
        }
        for(int i = 0; i < n; i++) {
            dp[i][j] = min(min(i>0?dp[i-1][j]:BB, i<n-1?dp[i+1][j]:BB) + a[i][j], dp[i][j]);
        }
        for(int i = 0; i < n; i++) {
            dp[i][j] = min(min(i>0?dp[i-1][j]:BB, i<n-1?dp[i+1][j]:BB) + a[i][j], dp[i][j]);
        } // I don't know how many times I should do, but to eliminate the side-effects, I need to do so
    }
    int ans = BB;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d%c", dp[i][j], j==n-1?'\n':' ');
        }
        ans = min(dp[i][n-1], ans);
    }
    cout << ans << endl;
}
