#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int MM = 1e5 + 5;
int lpf[MM];
vector<int> pr;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    for (int i = 2; i < MM; i++) {
        if (!lpf[i]) lpf[i] = i, pr.push_back(i);
        for (int j = 0; j < pr.size() && pr[j] <= lpf[i] && i * pr[j] < MM; j++) lpf[i * pr[j]] = pr[j];
    }
}