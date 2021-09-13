#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e5 + 5;
int N, sz[MM]; ll ans;
bool done[MM];
vector<int> adj[MM];
void getsz(int u, int pa) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == pa || done[v]) continue;
        getsz(v, u); sz[u] += sz[v];
    }
}
int getcent(int u, int pa, int tot) {
    for (int v : adj[u]) {
        if (v != pa && !done[v] && sz[v] * 2 > tot) return getcent(v, u, tot);
    }
    return u;
}
void solve(int rt) {
    getsz(rt, 0), rt = getcent(rt, 0, sz[rt]); done[rt] = true;
    for (int v : adj[rt]) {
        if (done[v]) continue;
        //perform some function:

    }
    for (int v : adj[rt]) {
        if (!done[v]) solve(v);
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    solve(1);
}