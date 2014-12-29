#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string smallMultiply(int small, string large) {
    int step = 0;
    int l = large.size();
    string ans;
    for(int i = l - 1; i >= 0; i --) {
        int temp = (large[i] - '0') * small + step;
        step = temp / 10;
        temp %= 10;
        ans += (temp + '0');
    }
    while(step > 0) {
        int temp = step;
        step = temp / 10;
        temp %= 10;
        ans += (temp + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int ans[1005];
    ans[0] = 1;
    string in = "1";
    for(int i = 1; i <= 1000; i++) {
        in = smallMultiply(i, in);
        ans[i] = 0;
        for(auto j : in) {
            ans[i] += (j - '0');
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}
