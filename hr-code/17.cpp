#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string conv(long long num) {
    if(num == 0) return "";
    string small[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
        "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string big[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    int o = num / 100, a = (num % 100) / 10, b = num % 10;
    string ans = "";
    bool flag = false;
    if(o != 0) {
        ans += small[o-1] + " " + "Hundred";
        flag = true;
    }
    if((a == 0 && b != 0) || a == 1) {
        ans += (flag?" ":"") + small[(num % 100) - 1];
    } else if(a > 1) {
        ans += (flag?" ":"") + big[a-2] + (b > 0?" " + small[b-1]:"");
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        if(n == 0) {
            cout << "Zero" << endl;
            continue;
        }
        vector <string> ans;

        string temp[] = {"Trillion", "Billion", "Million", "Thousand"};
        long long mod = 1000000000000ll;
        long long a;
        for(int i = 0; i < 4; i++) {
            a = n / mod;
            if(a > 0) {
                n %= mod;
                string ret = conv(a);
                if(ret != "") {
                    ans.push_back(ret + " " + temp[i]);
                }
            }
            mod /= 1000;
        }
        // cout << "!!" << ans.size() << endl;
        string ret = conv(n);
        if(ret != "") {
            ans.push_back(ret);
        }
        string out = "";
        for(auto i : ans) {
            out += i;
            out += " ";
        }
        out.pop_back();
        cout << out << endl;
    }
    return 0;
}
