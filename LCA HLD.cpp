#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int MM = 1e6 + 5;
int N, Q, sz[MM], dep[MM], par[MM], son[MM], top[MM];
vector<int> adj[MM];
void dfs1(int u, int pa) {
    dep[u] = dep[pa] + 1, sz[u] = 1, par[u] = pa;
    for (int v : adj[u]) {
        if (v == pa) continue;
        dfs1(v, u);
        if (sz[v] > sz[son[u]]) son[u] = v;
        sz[u] += sz[v];
    }
}
void dfs2(int u, int pa) {
    if (son[u]) {
        top[son[u]] = top[u];
        dfs2(son[u], u);
    }
    for (int v : adj[u]) {
        if (v == pa || v == son[u]) continue;
        dfs2(top[v] = v, u);
    }
}
int LCA(int u, int v) {
    for (; top[u] != top[v]; u = par[top[u]])
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
    return (dep[u] < dep[v]) ? u : v;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> Q;
    dfs1(1, 0), dfs2(top[1] = 1, 0);

}