#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
//modified from https://cp-algorithms.com/geometry/grahams-scan-convex-hull.html
struct pt {
    double x, y;
};
vector<pt> a;
bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cw(pt a, pt b, pt c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}
bool ccw(pt a, pt b, pt c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
void convex_hull() {
    if (a.size() == 1) return;
    sort(a.begin(), a.end(), cmp);
    vector<pt> up, down;
    pt p1 = a.front(), p2 = a.back();
    up.push_back(p1), down.push_back(p1);
    for (int i = 0; i < a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i])) up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i])) down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (int i = 0; i < up.size(); i++) a.push_back(up[i]);
    for (int i = down.size() - 2; i >= 0; i--) a.push_back(down[i]);
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    convex_hull();
}