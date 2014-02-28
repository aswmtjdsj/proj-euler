#include <cstdio>
#include <iostream>

using namespace std;

long long dp[25][25];

int main() {
    dp[0][0] = 1;
    for(int i = 0; i <= 20; i++) {
        for(int j = 0; j <= 20; j++) {
            if(i == 0 && j == 0) continue;
            dp[i][j] = (i > 0?dp[i-1][j]:0) + (j > 0?dp[i][j-1]:0);
            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
}
