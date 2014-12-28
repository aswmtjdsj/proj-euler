#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    return (b == 0)?a:gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    long long ans[42];
    ans[0] = 1;
    for(int i = 1; i <= 40; i++) {
        ans[i] = lcm(i, ans[i-1]);
    }
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}

