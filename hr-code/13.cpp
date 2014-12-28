#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string add(string num1, string num2) {
    int l1 = num1.size(), l2 = num2.size();
    string ans;
    int i = l1 - 1, j = l2 - 1;
    int step = 0;
    while(i >= 0 && j >= 0) {
        int a = num1[i] - '0', b = num2[j] - '0';
        int temp = a + b + step;
        step = (temp > 9) ? 1: 0;
        temp %= 10;
        ans += (temp + '0');
        i--; j--;
    }
    while(i >= 0) {
        int a = num1[i] - '0';
        int temp = a + step;
        step = (temp > 9) ? 1: 0;
        temp %= 10;
        ans += (temp + '0');
        i--;
    }
    while(j >= 0) {
        int a = num2[j] - '0';
        int temp = a + step;
        step = (temp > 9) ? 1: 0;
        temp %= 10;
        ans += (temp + '0');
        j--;
    }
    if(step > 0) {
        ans += (step + '0');
        step = 0;
    }
    reverse(ans.begin(), ans.end());
    for(i = 0; i < ans.size(); i++) {
        if(ans[i] != '0') {
            break;
        }
    }
    ans = ans.substr(i);
    if(ans.size() == 0) ans = "0";
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    string ans = "0";
    while(n--) {
        string opt;
        cin >> opt;
        ans = add(ans, opt);
    }
    cout << ans.substr(0, 10) << endl;
    return 0;
}
