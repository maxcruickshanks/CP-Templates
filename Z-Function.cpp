#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
//modified from https://cp-algorithms.com/string/z-function.html
const int MM = 1e5 + 5;
int Z[MM];
string s;
void z_function(string& s, int* z) {
    int n = (int)s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i + 1] = min (r - i + 1, z[i - l + 1]);
        while (i + z[i + 1] < n && s[z[i + 1]] == s[i + z[i + 1]]) ++z[i + 1];
        if (i + z[i + 1] - 1 > r) l = i, r = i + z[i + 1] - 1;
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> s;
    z_function(s, Z);

}