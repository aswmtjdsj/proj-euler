#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

using namespace std;

void itoa(long long x, char *buf) {
    sprintf(buf, "%lld", x);
}

bool in_vec(int x, vector<char> &vq) {
    char c = x + '0';
    for(vector<char>::iterator it = vq.begin(); it != vq.end(); it++) {
        if( c == *it) {
            return true;
        }
    }
    return false;
}

bool uni(char * buf) {
    map <int, bool> M;
    for(int i = 0;i < strlen(buf); i++) {
        if(M[buf[i]]) {
            return false;
        }
        else {
            M[buf[i]] = true;
        }
    }
    return true;
}

void dfs(vector <char> &vq, long long &ans) {
    int array[10] = { 17, 13, 11, 7, 5, 3, 2, 1};
    for(int i = 3; i <= 10; i++) {
        if(i == vq.size()) {
            char buff[5];

            if( i == 10) {
                long long count = 0, pw = 1;
                char buf[15];
                for(vector<char>::iterator it = vq.begin(); it != vq.end(); it++) {
                    count += pw * (*it - '0');
                    pw *= 10;
                }
                itoa(count, buf);
                printf("%s\n", buf);
                ans += count;
                return ;
            }

            for(int j = 0; j < 10; j++) {
                if(!in_vec(j, vq)) {
                    if( i < 9) {
                        int temp = j * 100 + (vq[vq.size()-1] - '0') * 10 + (vq[vq.size()-2] - '0');
                        if(temp % array[i-2] == 0) {
                            vq.push_back(j + '0');
                            dfs(vq, ans);
                            vq.pop_back();
                        }
                    }
                    else {
                        vq.push_back(j + '0');
                        dfs(vq, ans);
                        vq.pop_back();
                    }
                }
            }
        }
    }
}

int main() {
    long long ans = 0;
    for(int x = 1; x * 17 < 1000; x++) {
        char app[100];
        itoa(x * 17, app);
        //printf("%s\n", app);
        if(uni(app)) {
            vector <char> vq;
            for(int i = strlen(app) - 1; i >= 0; i--) { // reverse order
                vq.push_back(app[i]);
            }
            if(strlen(app) < 3) {
                vq.push_back('0');
            }
            dfs(vq, ans);
            for(int i = 0;i < 3; i++) 
                vq.pop_back();
        }
        else {
            //puts("not unique");
        }
    }
    printf("%lld\n", ans);
}
