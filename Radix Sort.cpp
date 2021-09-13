#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
const int DIG = 15, MM = 1e5 + 5;
int D[DIG], N, M, TMP[MM];
pi BSA[MM], AUX[MM];
vector<int> CUR[DIG];

//warning: this does not sort 0 properly:
void radix(int *OG) {
    for (int i = 1; i <= N; i++) {
        TMP[i] = OG[i], BSA[i] = {OG[i], i}, M = max(M, (int)log10(OG[i]) + 1), D[(int)log10(OG[i]) + 1]++;
    }
    for (int i = 1; i < DIG; i++) D[i] += D[i - 1];
    for (int rnd = 1; rnd <= M; rnd++) {
        for (int i = 0; i < DIG; i++) CUR[i].clear();
        int pos = D[rnd - 1] + 1, p2 = 1;
        for (int i = 1; i <= N; i++) {
            if (BSA[i].f) CUR[BSA[i].fi % 10].push_back(i);
            else AUX[p2++] = BSA[i];
        }
        for (int i = 0; i < DIG; i++) {
            for (int idx : CUR[i]) AUX[pos++] = {BSA[idx].f / 10, BSA[idx].se};
        }
        for (int i = 1; i <= N; i++) BSA[i] = AUX[i];
    }
    for (int i = 1; i <= N; i++) OG[i] = TMP[BSA[i].se];
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

}