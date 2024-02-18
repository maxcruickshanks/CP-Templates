#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
template<typename T> struct BIT {
    vector<T> bit;
    BIT(int N) {
        bit.resize(N + 5);
        clear();
    }
    void clear() {
        fill(bit.begin(), bit.end(), 0);
    }
    void update(T idx, T v) {
        for (; idx < bit.size(); idx += idx & -idx) bit[idx] += v;
    }
    T sum(T idx) {
        T ret = 0;
        for (; idx > 0; idx -= idx & -idx) ret += bit[idx];
        return ret;
    }
};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

}