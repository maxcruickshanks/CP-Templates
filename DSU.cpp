#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int MM = 1e5 + 5;
struct DSU {
    int PA[MM], SZ[MM];
    void Init(int N) {
        iota(PA+1, PA+N+1, 1), fill(SZ+1, SZ+N+1, 1);
    }
    int Find(int x) {
        return (PA[x] == x) ? x : PA[x] = Find(PA[x]);
    }
    bool Union(int x, int y) {
        if ((x = Find(x)) == (y = Find(y))) return 0;
        if (SZ[x] > SZ[y]) swap(x, y);
        return SZ[y] += SZ[x], PA[x] = y, 1;
    }
};
struct rb {
    int x, y, sx, sy;
};
struct DSURB {
    int PA[MM], SZ[MM];
    stack<rb> stk;
    void Init(int N) {
        iota(PA+1, PA+N+1, 1), fill(SZ+1, SZ+N+1, 1);
    }
    int Find(int x) {
        return (PA[x] == x) ? x : PA[x] = Find(PA[x]);
    }
    bool Union(int x, int y) {
        stk.push({x = Find(x), y = Find(y), SZ[x], SZ[y]});
        if (x == y) return 0;
        if (SZ[x] < SZ[y]) swap(x, y);
        return PA[y] = x, SZ[x] += SZ[y], 1;
    }
    void Undo() {
        if(stk.empty()) return;
        rb e = stk.top(); stk.pop();
        PA[e.x] = e.x; PA[e.y] = e.y;
        SZ[e.x] = e.sx; SZ[e.y] = e.sy;
    }
    void UndoAll() {
        while(!stk.empty()) Undo();
    }
};
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

}