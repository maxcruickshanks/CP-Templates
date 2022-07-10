#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 2e5 + 5;
int N, M, a[MM], dfn[MM], low[MM], stk[MM], in[MM], scc[MM], cnt, tp = -1;
vector<int> adj[MM];
void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    stk[++tp] = u; in[u] = true;
    for (int v : adj[u]) {
        //if (v == pa)
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        int x;
        do {
            x = stk[tp--];
            scc[x] = u;
            in[x] = false;
        } while(x != u);
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

}