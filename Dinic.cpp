#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
struct edge {
    int u, v; ll cap, flow = 0;
    edge(int u, int v, ll cap) : v(v), u(u), cap(cap) {}
};
struct dinic {
    const ll flow_inf = 1e18;
    vector<edge> edges;
    vector<vector<int>> adj;
    int n, m = 0, s, t;
    vector<int> level, ptr;
    queue<int> q;

    dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n), level.resize(n), ptr.resize(n);
    }

    void add_edge(int u, int v, ll cap) {
        edges.pb({u, v, cap}), edges.pb({v, u, 0});
        adj[u].pb(m), adj[v].pb(m + 1), m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1 || level[edges[id].u] != -1) continue;
                level[edges[id].u] = level[v] + 1; q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, long long pushed) {
        if (!pushed) return 0;
        if (v == t) return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid], u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1) continue;
            ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (!tr) continue;
            edges[id].flow += tr, edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    ll flow() {
        ll f = 0;
        while (1) {
            fill(level.begin(), level.end(), -1); level[s] = 0; q.push(s);
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, flow_inf)) f += pushed;
        }
        return f;
    }
};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

}