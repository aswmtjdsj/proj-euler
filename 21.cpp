#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2000;
const int T = 10000;
int a[N];
bool v[T];
int tot = 0;

int tie[T*10];

int main() {

    memset(tie, 0, sizeof(tie));
    int ans = 0;
    for(int i = 2; i <= T; i++) {
        int bla = 0;
        for(int j = i-1; j >= 1; j--) {
            if(i % j == 0) {
                bla += j;
            }
        }
        tie[i] = bla;
        cout << i << ' ' << bla << endl;
        if(tie[bla] == i && i != bla) {
            ans += bla + i;
            cout << bla << ' ' << i << endl;
        }

    }
    cout << ans << endl;
}
