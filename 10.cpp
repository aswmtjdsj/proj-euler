#include <cstdio>
#include <iostream>
#include <cstring>

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

    for(int i = 0; i < tot; i++) {
        //cout << a[i] << endl;
        ans += a[i];
    }
    cout << ans << endl;
}
