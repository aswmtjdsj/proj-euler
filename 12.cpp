#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 200000;
const int T = 2000000;
int a[N];
bool v[T];
int tot = 0;
long long ans = 0;

int main() {

    memset(v, 1, sizeof(v));

    v[1] = false;

    for(int i = 2; i < T; i+=2) {
        v[i] = false;
    }
    v[2] = true;
    a[tot++] = 2;

    for(int i = 3; i < T; i++) {
        if(v[i]) {
            a[tot++] = i;
            for(int j = i * 2; j < T; j+=i) {
                v[j] = false;
            }
        }
    }

    /*for(int i = 0; i < tot; i++) {
        //cout << a[i] << endl;
        ans += a[i];
    }*/
    //cout << ans << endl;
    //
    long long tr = 0;
    int num = 1;
    while(1){
        tr += num;
        int cnt = 1;
        long long temp = tr;
        int id = upper_bound(a, a + tot, tr) - a;
        for(int i = id - 1; i >= 0; i--) {
            int tt = 1;
            while(temp % a[i] == 0) {
                temp /= a[i];
                tt ++;
            }
            cnt *= tt;
        }
        cout << tr << ' ' << cnt << endl;
        num ++;
        if(cnt > 500) break;
    }
    cout << tr << endl;
}
