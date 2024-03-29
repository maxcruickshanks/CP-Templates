#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e6 + 5;
struct node {
    int l, r, mx;
} seg[4 * MM];
int A[MM], N;
void pushup(int rt) {
    if (seg[rt].l == seg[rt].r) return;
    int lc = 2 * rt, rc = 2 * rt + 1;
    seg[rt].mx = max(seg[lc].mx, seg[rc].mx);
}
void build(int rt, int l, int r) {
    seg[rt].l = l, seg[rt].r = r;
    if (l == r) {
        seg[rt].mx = A[l]; return;
    }
    int mid = (l + r) / 2;
    build(2 * rt, l, mid), build(2 * rt + 1, mid + 1, r);
    pushup(rt);
}
int query(int rt, int l, int r) {
    if (seg[rt].r < l || seg[rt].l > r) return INT_MIN;
    if (l <= seg[rt].l && seg[rt].r <= r) return seg[rt].mx;
    return max(query(2 * rt, l, r), query(2 * rt + 1, l, r));
}
void update(int rt, int idx, int v) {
    if (seg[rt].l > idx || seg[rt].r < idx) return;
    if (seg[rt].l == idx && seg[rt].r == idx) {
        seg[rt].mx = max(seg[rt].mx, v); return;
    }
    update(2 * rt, idx, v), update(2 * rt + 1, idx, v);
    pushup(rt);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    build(1, 1, N);
    query(1, 1, N);
}