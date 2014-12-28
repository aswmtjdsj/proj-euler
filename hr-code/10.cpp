#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime[1000005] = {true};
int prime[100005];
long long prime_sum[100005];
int cnt;

void sieve() {
    fill(is_prime, is_prime + 1000001, true);
    cnt = 0;
    prime[cnt] = 2;
    prime_sum[cnt++] = 2;

    for(int i = 3; i <= 1000000; i += 2) {
        if(is_prime[i]) {
            for(int j = i * 3; j <= 1000000; j += i) {
                is_prime[j] = false;
            }
            prime[cnt] = i;
            prime_sum[cnt] = i + prime_sum[cnt-1];
            cnt++;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    sieve();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        auto p = upper_bound(prime, prime + cnt, n);
        // cout << *p << endl;
        int idx = p - prime;
        // cout << idx << endl;
        cout << prime_sum[idx-1] << endl;
    }
    return 0;
}
