#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 200

int dp[N][N];
int a[N][N];

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
    memset(dp, 0x7f7f7f7f, sizeof(dp));
    dp[0][0] = a[0][0];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) continue;
            dp[i][j] = min(i>0?dp[i-1][j]:0x7f7f7f7f, j>0?dp[i][j-1]:0x7f7f7f7f) + a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d%c", dp[i][j], j==n-1?'\n':' ');
        }
    }
    cout << dp[n-1][n-1] << endl;
}
