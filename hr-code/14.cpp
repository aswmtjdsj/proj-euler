#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector <int> loop, cnt, ans;
int N;

int dfs(long long num) {
    // cout << num << endl;
    if(num < N && loop[num] != -1) return loop[num] + 1;
    int ret;
    if(num % 2 == 0) {
        ret = dfs(num / 2);
    } else {
        ret = dfs(num * 3 + 1);
    }
    if(num < N) {
        loop[num] = ret;
    }
    return ret + 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    N = 5000001;
    // N = 21;
    loop.resize(N);
    cnt.resize(N);
    ans.resize(N);
    fill(loop.begin(), loop.end(), -1);
    fill(cnt.begin(), cnt.end(), 0);
    loop[1] = 1;
    cnt[1] = 1;
    ans[1] = 1;
    for(int i = 2; i < N; i++) {
        int ret = dfs(i);
        if(loop[i] == -1) {
            loop[i] = ret;
        }
        if(loop[i] >= cnt[i-1]) {
            cnt[i] = loop[i];
            ans[i] = i;
        } else {
            cnt[i] = cnt[i-1];
            ans[i] = ans[i-1];
        }
        // cout << i << ' ' << loop[i] << endl;
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
