#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N;
int * primes;
bool * is_prime;
int tot;

void gen() {
    memset(is_prime, false, sizeof(is_prime));
    for(int i = 3; i < N; i+=2) {
        is_prime[i] = true;
    }

    for(int i = 3; i < N; i+=2) {
        if(is_prime[i]) {
            for(int j = i << 1; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    tot = 0;
    primes[tot++] = 2;
    for(int i = 3; i < N; i+=2) {
        if(is_prime[i]) {
            primes[tot++] = i;
        }
    }
}

int main(int argc, char ** argv) {
    if( argc != 2) {
        cout << "please input <param>!" << '\n';
        return 1;
    }
    else {
        sscanf(argv[1], "%d", &N);
        N = N+1;
        primes = new int[N];
        is_prime = new bool[N];
        gen();
        char file_name[100];
        sprintf(file_name, "primes_%d.out", N-1);
        printf("%s generated!\n", file_name);
        FILE * fp = fopen(file_name, "w");
        for(int i = 0; i < tot; i++) {
            fprintf(fp, "%d ", primes[i]);
        }
        fclose(fp);
        delete [] primes;
        delete [] is_prime;
        /*for(int i = 0; i < tot; i++) {
            cout << primes[i] << (i == tot - 1?'\n':' ');
        }*/
    }
}
