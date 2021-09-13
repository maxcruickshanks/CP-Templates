#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
struct BIT {
    ll BIT[MM];
    void Update(int idx, ll v) {
        for (; idx < MM; idx += idx & -idx) BIT[idx] += v;
    }
    ll Sum(int idx) {
        ll ret = 0;
        for (; idx > 0; idx -= idx & -idx) ret += BIT[idx];
        return ret;
    }
};
struct BITRB {
    vector<pll> BIT[MM];
    stack<vector<int>> stk;
    void Init(int N, int v) {
        for (int i = 1; i <= N; i++) BIT[i].push_back({0, v});
    }
    void Update(int idx, ll v) {
        stk.push({});
        for (; idx < MM; idx += idx & -idx) BIT[idx].push_back({stk.size(), BIT[idx].back().se + v}), stk.top().push_back(idx);
    }
    ll Sum(int idx, int dec) {
        ll ret = 0;
        for (; idx > 0; idx -= idx & -idx) {
            auto it = upper_bound(BIT[idx].begin(), BIT[idx].end(), make_pair(stk.size() - dec, -INF));
            ret += (--it)->second;
        }
        return ret;
    }
};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

}