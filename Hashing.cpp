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
    const static int mod = 1e9 + 7;
    static int global_base1, global_base2;
    static vector<long long> powers1, inv_powers1, powers2, inv_powers2;
    vector<long long> psa;

    hashes(T& s, int b = 131) : rng(chrono::steady_clock::now().time_since_epoch().count()), psa{0} {
        int base = R ? uniform_int_distribution<int>(200, 1000000000)(rng) : b, inv = 1;
        int& chosen_base = LEFT_HASH ? global_base1 : global_base2;
        if (chosen_base) {
            base = chosen_base;
            inv = (LEFT_HASH ? inv_powers1 : inv_powers2)[1];
        }
        else {
            chosen_base = base;
            long long cur = base;
            for (int exp = mod - 2; exp; exp >>= 1) {
                if (exp & 1) inv = inv * cur % mod;
                cur = cur * cur % mod;
            }
        }
        compute_powers(s, base, inv);
        for (int i = 0; i < s.size(); i++) {
            psa.push_back((psa.back() + s[i] * (LEFT_HASH ? powers1 : powers2)[i]) % mod);
        }
    }

    static void compute_powers(T &s, int base, int inv) {
        vector<long long> &powers = LEFT_HASH ? powers1 : powers2,
            &inv_powers = LEFT_HASH ? inv_powers1 : inv_powers2;

        for (int i = powers.size(); i <= s.size(); i++) {
            powers.push_back(powers.back() * base % mod);
            inv_powers.push_back(inv_powers.back() * inv % mod);
        }
    }

    hashes() {}

    long long get(int l, int r) {
        return (psa[r + 1] - psa[l] + mod) * (LEFT_HASH ? inv_powers1 : inv_powers2)[l] % mod;
    }
};
template<typename T, bool R, bool LEFT_HASH> int hashes<T, R, LEFT_HASH>::global_base1 = 0; template<typename T, bool R, bool LEFT_HASH> int hashes<T, R, LEFT_HASH>::global_base2 = 0; template<typename T, bool R, bool LEFT_HASH> vector<long long> hashes<T, R, LEFT_HASH>::powers1 = {1}; template<typename T, bool R, bool LEFT_HASH> vector<long long> hashes<T, R, LEFT_HASH>::powers2 = {1}; template<typename T, bool R, bool LEFT_HASH> vector<long long> hashes<T, R, LEFT_HASH>::inv_powers1 = {1}; template<typename T, bool R, bool LEFT_HASH> vector<long long> hashes<T, R, LEFT_HASH>::inv_powers2 = {1};

template<typename T, bool R = true>
struct double_hash {
    hashes<T, R, true> hash1;
    hashes<T, R, false> hash2;

    double_hash(T& s, int base1 = 131, int base2 = 173) : hash1(hashes<T, R, true>(s, base1)),
                                                          hash2(hashes<T, R, false>(s, base2)) {}
    double_hash() {}

    long long get(int l, int r) {
        return (hash1.get(l, r) << 32) | hash2.get(l, r);
    }
};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

}
