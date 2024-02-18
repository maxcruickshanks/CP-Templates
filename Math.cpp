#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
const int MOD = 1e9 + 7, MM = 1e6 + 5;
long long fac[MM];
bool is_prime(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
vector<long long> sieve(int mx) {
    vector<long long> pr, lpf(mx, 0);
    for (ll i = 2; i < mx; i++) {
        if (!lpf[i]) lpf[i] = i, pr.push_back(i);
        for (ll j = 0; j < pr.size() && pr[j] <= lpf[i] && i * pr[j] < MM; j++) lpf[i * pr[j]] = pr[j];
    }
}
vector<long long> factors(long long n) {
    vector<long long> ret;
    long long bs = sqrt(n);
    for (long long i = 2; i <= bs; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) ret.push_back(n);
    return ret;
}
vector<long long> divisors(long long n) {
    vector<long long> ret;
    long long bs = sqrt(n);
    for (long long i = 1; i <= bs; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (n / i != i) ret.push_back(n / i);
        }
    }
    return ret;
}
//modified from https://cp-algorithms.com/algebra/phi-function.html
long long totient(long long n) {
    long long result = n;
    //O(sqrt(n)):
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}
vector<long long> sieve(long long mx) {
    vector<long long> phi(mx);
    for (int i = 1; i <= mx; i++) phi[i] = i;
    for (int i = 2; i <= mx; i++) {
        if (phi[i] == i) {
            for (int j = i; j  <= mx; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}
long long qpow(long long b, long long p) {
    if (p == 0) return 1;
    long long res = qpow(b, p / 2);
    res = (res * res) % MOD;
    if (p & 1) res = (res * b) % MOD;
    return res;
}
long long inverse(long long x) {
    return qpow(x, MOD - 2);
}
long long divide(long long x, long long y) {
    return (x * inverse(y)) % MOD;
}
long long choose(long long n, long long k) {
    return divide(fac[n], (fac[k] * fac[n - k]) % MOD);
}
long long gcd(long long a, long long b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

}