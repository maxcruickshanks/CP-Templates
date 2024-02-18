#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
//modified from https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html
const int MM = 105;
int MT[MM], VIS[MM];
vector<int> adj[MM];
bool try_kuhn(int u) {
    if (VIS[u]++) return false;
    for (int v : adj[u]) if (MT[v] == -1 || try_kuhn(MT[v])) return MT[v] = u, true;
    return false;
}
int kuhn() {
    memset(MT, -1, sizeof(MT));
    int mtch = 0;
    for (int u = 1; u < MM; u++) memset(VIS, 0, sizeof(VIS)), mtch += try_kuhn(u);
    return mtch;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

}