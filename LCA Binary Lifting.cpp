#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int MM = 1e5 + 5, LOG = 18;
int lca[LOG][MM], dep[MM];
vector<int> adj[MM];

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) {
        if (dep[lca[i][u]] >= dep[v]) u = lca[i][u];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--)
        if (lca[i][u] != lca[i][v]) u = lca[i][u], v = lca[i][v];
    return lca[0][u];
}
void dfs1(int u, int pa) {
    lca[0][u] = pa; dep[u] = dep[pa] + 1;
    for (int i = 1; i < LOG; i++) lca[i][u] = lca[i - 1][lca[i - 1][u]];
    for (int v : adj[u])
        if (v != pa) dfs1(v, u);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    dfs1(1, 0);

}