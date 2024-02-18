#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
struct DSU {
    vector<int> PA, SZ;
    int N;
    DSU() {}
    DSU(int N) : N{N} {
        PA.resize(N+1); SZ.resize(N+1);
        iota(PA.begin(), PA.end(), 0), fill(SZ.begin(), SZ.end(), 1);
    }
    int Find(int x) {
        return (PA[x] == x) ? x : PA[x] = Find(PA[x]);
    }
    bool Union(int x, int y) {
        if ((x = Find(x)) == (y = Find(y))) return 0;
        if (SZ[x] > SZ[y]) swap(x, y);
        return SZ[y] += SZ[x], PA[x] = y, 1;
    }
    vector<vector<int>> Groups() {
        vector<int> leader_buf(N), group_size(N);
        for (int i = 0; i < N; i++) {
            leader_buf[i] = Find(i);
            group_size[leader_buf[i]]++;
        }
        vector<vector<int>> result(N);
        for (int i = 0; i < N; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < N; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
                std::remove_if(result.begin(), result.end(),
                               [&](const std::vector<int>& v) { return v.empty(); }),
                result.end());
        return result;
    }
};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

}