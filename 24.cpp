#include "header.h"

int main() {
    int biu[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int cnt = 0;
    do {
        cnt++;
        if(cnt == 1000000) {
            for(int i = 0; i < 10; i++) {
                cout << biu[i];
            }
            cout << endl;
        }
    } while(next_permutation(biu, biu + 10));
}
