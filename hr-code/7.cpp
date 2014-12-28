#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool vis[200000] = {false};
int prime[10005];
int cnt = 0;

void sieve() {
    vis[2]  = 1;
    prime[cnt++] = 2;

    for(int i = 3; i < 200000; i += 2) {
        vis[i] = true;
    }

    for(int i = 3; i < 200000; i += 2) {
        if(vis[i]) {
            prime[cnt++] = i;
            for(int j = i * 2; j < 200000; j += i) {
                vis[j] = false;
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    sieve();
    int n, a;
    cin >> n;
    while(n--) {
        cin >> a;
        cout << prime[a-1] << endl;
    }
    return 0;
}
