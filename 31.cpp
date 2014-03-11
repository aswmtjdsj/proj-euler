#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int dp[201];
int main() {
    int value[10] = {1, 2, 5, 10, 20, 50, 100, 200 };
    int n = 8;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < 8; i++) {
        for(int j = value[i]; j <= 200; j ++) {
            dp[j] += dp[j-value[i]];
        }
    }
    for(int i = 0; i <= 200; i++) {
        printf("%d\n", dp[i]);
    }
}
