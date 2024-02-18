#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
const int MN = 20, MM = 1e5 + 5;
int st[MN][MM], N;
int query(int l, int r) {
    int lvl = 31 - __builtin_clz(r-l+1);
    return min(st[lvl][l], st[lvl][r - (1 << lvl) + 1]);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    for (int i = 1; i <= N; i++) st[0][i] = 1;
    for (int lvl = 1; lvl < MN; lvl++) {
        for (int i = 0; i + (1 << lvl) <= N; i++)
            st[lvl][i] = min(st[lvl - 1][i], st[lvl - 1][i + (1 << (lvl - 1))]);
    }
}