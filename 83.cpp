#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define N 100

struct edge {
    int to, val;
    edge() {}
    edge(int n, int v): to(n), val(v){}
};

vector <vector<edge> > graph;

void add(int p, int q, int val) {
    graph[p].push_back(edge(q, val));
}

int ma[N][N], dis[N*N];
const int BB = 0x7f7f7f7f;
bool in[N*N];

void spfa(int s, int t) {
    memset(in, 0, sizeof(in));
    in[s] = true;
    queue <int> Q;
    Q.push(s);
    dis[s] = 0;
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        in[cur] = false;
        for(int i = 0; i < graph[cur].size(); i++) {
            edge e = graph[cur][i];
            if(dis[e.to] > dis[cur] + e.val) {
                dis[e.to] = dis[cur] + e.val;
                if(!in[e.to]) {
                    in[e.to] = true;
                    Q.push(e.to);
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    graph.resize(n*n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j == n-1)
                scanf(" %d", &ma[i][j]);
            else
                scanf(" %d,", &ma[i][j]);
        }
    }
    // i * n + j
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i > 0) {
                add(i*n+j, (i-1)*n+j, ma[i-1][j]);
            }
            if(i < n - 1) {
                add(i*n+j, (i+1)*n+j, ma[i+1][j]);
            }
            if(j > 0) {
                add(i*n+j, i*n+j-1, ma[i][j-1]);
            }
            if(j < n - 1) {
                add(i*n+j, i*n+j+1, ma[i][j+1]);
            }
        }
    }
    memset(dis, BB, sizeof(dis));
    spfa(0, n*n-1);
    cout << dis[n*n-1] + ma[0][0] << endl;

}
