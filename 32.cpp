#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {

    int a[9];
    for(int i = 1; i <= 9; i++) {
        a[i-1] = i;
    }

    int ans = 0;
    set<int> S;
    do {
        int l, m, r;
        for(int i = 0; i < 8; i++) {
            for(int j = i + 1; j < 8; j++) {
                int up = 1;
                l = m = r = 0;
                for(int p = 0; p <= i; p++) {
                    l += a[p] * up;
                    up *= 10;
                }

                up = 1;
                for(int p = i + 1; p <= j; p++) {
                    m += a[p] * up;
                    up *= 10;
                }

                up = 1;
                for(int p = j + 1; p < 9; p++) {
                    r += a[p] * up;
                    up *= 10;
                }

                if(l * m == r && S.insert(r).second != false) {
                    printf("%d %d %d\n", l, m, r);
                    ans += r;
                }
            }
        }
        
    } while(next_permutation(a, a + 9));

    printf("%d\n", ans);
}
