#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long sum(long long n) {
    return n * (n + 1) / 2;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long a = (n-1) / 3, b = (n-1) / 5, c = (n-1) / 15;
        cout << 3 * sum(a) + 5 * sum(b) - 15 * sum(c) << endl;
    }
    return 0;
}
