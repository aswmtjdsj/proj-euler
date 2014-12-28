#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime[1000005] = {true};
int prime[100005];
int cnt;

void sieve() {
    fill(is_prime, is_prime + 1000000, true);
    cnt = 0;
    prime[cnt++] = 2;

    for(int i = 3; i <= 1000000; i += 2) {
        if(is_prime[i]) {
            for(int j = i * 3; j <= 1000000; j += i) {
                is_prime[j] = false;
            }
            prime[cnt++] = i;
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long n;
    int t;
    cin >> t;
    sieve();
    while(t--) {
        cin >> n;
        int i = 0;
        long long ans = 1;
        while(i < cnt) {
            if(n % prime[i] == 0) {
                n /= prime[i];
                ans = prime[i];
            } else {
                i++;
            }
        }
        if(n != 1) {
            ans = max(ans, n);
        }
        cout << ans << endl;
    }
    return 0;
}
