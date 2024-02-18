#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
//modified from https://www.youtube.com/watch?v=czySm7bUHgY
const int MM = 2e5 + 5, LOG = 20;
int n, lca[MM][LOG], st[MM], en[MM], dep[MM], dfs_time;
vector<int> adj[MM], vrt[MM];
void dfs_lca(int u, int pa) {
    dep[u] = dep[pa] + 1;
    lca[u][0] = pa;
    for (int i = 1; i < LOG; i++) lca[u][i] = lca[lca[u][i - 1]][i - 1];
    st[u] = ++dfs_time;
    for (int v : adj[u]) {
        if (v != pa) dfs_lca(v, u);
    }
    en[u] = dfs_time;
}
bool is_above(int u, int v) {
    return st[u] <= st[v] && en[v] <= en[u];
}
int LCA(int u, int v) {
    if (is_above(u, v)) return u;
    if (is_above(v, u)) return v;
    for (int i = LOG - 1; i >= 0; i--) {
        if (!is_above(lca[u][i], v)) u = lca[u][i];
    }
    return lca[u][0];
}
bool cmp_vrt(int u, int v) {
    return st[u] < st[v];
}
int build_vrt(vector<int> bd) {
    sort(bd.begin(), bd.end(), cmp_vrt);
    int n = bd.size();
    for (int i = 1; i < n; i++) bd.pb(LCA(bd[i - 1], bd[i]));
    sort(bd.begin(), bd.end(), cmp_vrt);
    bd.erase(unique(bd.begin(), bd.end()), bd.end());
    vector<int> stk; stk.pb(bd[0]);
    for (int i = 1; i < bd.size(); i++) {
        while (stk.size() >= 2 && !is_above(stk.back(), bd[i])) {
            vrt[stk[stk.size() - 2]].pb(stk.back());
            vrt[stk.back()].pb(stk[stk.size() - 2]);
            stk.pop_back();
        }
        stk.pb(bd[i]);
    }
    while (stk.size() >= 2) {
        vrt[stk[stk.size() - 2]].pb(stk.back());
        vrt[stk.back()].pb(stk[stk.size() - 2]);
        stk.pop_back();
    }
    return stk[0];
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs_lca(1, 0);

}