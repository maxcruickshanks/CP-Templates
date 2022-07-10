#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e5 + 5;
ll lpf[MM];
vector<ll> pr;
void sieve() {
    for (ll i = 2; i < MM; i++) {
        if (!lpf[i]) lpf[i] = i, pr.push_back(i);
        for (ll j = 0; j < pr.size() && pr[j] <= lpf[i] && i * pr[j] < MM; j++) lpf[i * pr[j]] = pr[j];
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

}