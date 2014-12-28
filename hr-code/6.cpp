#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long n;
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << (n * (n+1) / 2) * (n * (n+1) / 2) - n * (n+1) * (2*n+1) / 6 << endl;
    }
    return 0;
}
