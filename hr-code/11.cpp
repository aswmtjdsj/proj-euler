#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int grid[22][22];
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j <= 16; j++) {
            int cur = 1;
            for(int k = 0; k < 4; k++) {
                cur *= grid[i][j+k];
            }
            ans = max(cur, ans);
        }
    }
    for(int j = 0; j < 20; j++) {
        for(int i = 0; i <= 16; i++) {
            int cur = 1;
            for(int k = 0; k < 4; k++) {
                cur *= grid[i+k][j];
            }
            ans = max(cur, ans);
        }
    }
    for(int i = 0; i < 20; i++) {
        if(i + 4 > 20) {
            break;
        }
        for(int j = 0; j < 20; j++) {
            if(j + 4 > 20) {
                break;
            }
            int cur = 1;
            for(int k = 0; k < 4; k++) {
                cur *= grid[i+k][j+k];
            }
            ans = max(cur, ans);
        }
    }
    for(int i = 3; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            if(j + 4 > 20) {
                break;
            }
            int cur = 1;
            for(int k = 0; k < 4; k++) {
                cur *= grid[i-k][j+k];
            }
            ans = max(cur, ans);
        }
    }
    cout << ans << endl;
    return 0;
}
