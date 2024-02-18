#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
//modified from https://cp-algorithms.com/graph/edmonds_karp.html
const int INF = 1e9, MM = 505;
vector<int> adj[MM];
int cap[MM][MM];
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1); parent[s] = -2;
    queue<pi> q; q.push({s, INF});
    while (!q.empty()) {
        int cur = q.front().fi, flow = q.front().se; q.pop();
        for (int next : adj[cur]) {
            if (parent[next] == -1 && cap[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, cap[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}
int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(MM);
    int new_flow;
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            cap[prev][cur] -= new_flow, cap[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}
void add(int u, int v, int c) {
    adj[u].push_back(v), cap[u][v] = c;
    adj[v].push_back(u), cap[v][u] = 0;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

}