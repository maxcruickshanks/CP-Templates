#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
template<typename T, bool R = true, bool LEFT_HASH = true>
struct hashes {
    mt19937 rng;
    static int global_base1, global_base2;
    int base, inv, mod, sz;
    static vector<long long> powers, inv_powers;
    vector<long long> psa;

    hashes(T& s, int m = 1e9 + 7, int b = 131) : rng(chrono::steady_clock::now().time_since_epoch().count()),
                                                 base(R ? uniform_int_distribution<int>(200, 1000000000)(rng) : b),
                                                 inv(1), mod(m), sz(s.size()), psa{0} {
        int& chosen_base = LEFT_HASH ? global_base1 : global_base2;
        if (chosen_base) base = chosen_base;
        else chosen_base = base;
        long long cur = base;
        for (int exp = m - 2; exp; exp >>= 1) {
            if (exp & 1) inv = inv * cur % m;
            cur = cur * cur % m;
        }
        compute_powers(s, base, inv, mod);
        for (int i = 0; i < s.size(); i++) {
            psa.push_back((psa.back() + s[i] * powers[i]) % mod);
        }
    }
    
    static void compute_powers(T &s, int bs, int in, int md) {
        if (powers.empty()) {
            powers = {1}; inv_powers = {1};
        }
        for (int i = powers.size(); i < s.size(); i++) {
            powers.push_back(powers.back() * bs % md);
            inv_powers.push_back(inv_powers.back() * in % md);
        }
    }

    hashes() {}

    long long get(int l, int r) {
        return (psa[r + 1] - psa[l] + mod) * inv_powers[l] % mod;
    }
};

template<typename T, bool R, bool LEFT_HASH>
int hashes<T, R, LEFT_HASH>::global_base1 = 0;
template<typename T, bool R, bool LEFT_HASH>
int hashes<T, R, LEFT_HASH>::global_base2 = 0;

template<typename T, bool R = true>
struct double_hash {
    hashes<T, R, true> hash1;
    hashes<T, R, false> hash2;

    double_hash(T& s, int base1 = 131, int base2 = 173, int mod = 1e9 + 7) : hash1(hashes<T, R, true>(s, mod, base1)),
                                                                             hash2(hashes<T, R, false>(s, mod, base2)) {}
    double_hash() {}

    long long get(int l, int r) {
        return (hash1.get(l, r) << 32) | hash2.get(l, r);
    }
};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

}
