#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
//modified from https://cp-algorithms.com/algebra/phi-function.html
const int MM = 1e5 + 5;
ll n, PHI[MM];
ll totient(ll n) {
    ll result = n;
    //O(sqrt(n)):
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}
void sieve(ll mx) {
    for (int i = 1; i <= mx; i++) PHI[i] = i;
    for (int i = 2; i <= mx; i++) {
        if (PHI[i] == i) {
            for (int j = i; j  <= mx; j += i) {
                PHI[j] = PHI[j] / i * (i - 1);
            }
        }
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    cout << totient(n) << "\n";
}