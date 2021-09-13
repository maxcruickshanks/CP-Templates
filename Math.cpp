#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int MOD = 1e9 + 7, MM = 1e6 + 5;
ll fac[MM];
ll qpow(ll b, ll p) {
    if (p == 0) return 1;
    ll res = qpow(b, p / 2);
    res = (res * res) % MOD;
    if (p & 1) res = (res * b) % MOD;
    return res;
}
ll inverse(ll x) {
    return qpow(x, MOD - 2);
}
ll divide(ll x, ll y) {
    return (x * inverse(y)) % MOD;
}
ll choose(ll n, ll k) {
    return divide(fac[n], (fac[k] * fac[n - k]) % MOD);
}
ll mod(ll b, ll mod) {
    ll r = b / mod;
    return (b - r * mod + mod) % mod;
}
vector<ll> factors(ll n, bool mult) {
    vector<ll> ret;
    ll bs = sqrt(n);
    for (ll i = 2; i <= bs; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            while (n % i == 0) {
                n /= i;
                if (mult) ret.push_back(i);
            }
        }
    }
    if (n != 1) ret.push_back(n);
    return ret;
}
vector<ll> divisors(ll n) {
    vector<ll> ret;
    ll bs = sqrt(n);
    for (ll i = 1; i <= bs; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (n / i != i) ret.push_back(n / i);
        }
    }
    return ret;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    fac[0] = 1;
    for (int i = 1; i < MM; i++) fac[i] = (fac[i - 1] * i) % MOD;
}