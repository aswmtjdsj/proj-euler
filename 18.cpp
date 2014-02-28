#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 200

int a[N][N], dp[N][N];
int main() {
    memset(dp, 0, sizeof(dp));
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = max((i>1?dp[i-1][j]:0),(i>1&&j>1?dp[i-1][j-1]:0)) + a[i][j];
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans << endl;
}
