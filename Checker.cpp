#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
const int AC = 0;
const int WA = 1;
const int PE = 2;
const int IE = 3;
const int PARTIAL = 7;

ll read(FILE* f) {
    ll ret;
    char c = getc(f);
    if (('0' > c || c > '9') && (c != '-')) exit(PE);
    ungetc(c, f);
    if (fscanf(f, "%lld", &ret) != 1) exit(PE);
    return ret;
}
string read(FILE* f, char ch) {
    string ret = "";
    char c = getc(f);
    while (c != ch) {
        ret += c; c = getc(f);
    }
    ungetc(c, f);
    return ret;
}
void read(FILE* f, const char* s) {
    while (*s) {
        if (getc(f) != *s) exit(PE);
        s++;
    }
}
void read_eof(FILE* f) {
    if (getc(f) != EOF) exit(PE);
}
int partials(int cnt) {
    cerr << "partial " << cnt << "/100\n";
    return PARTIAL;
}
int wrong(string dbg, int res = WA) {
    cout << dbg << "\n";
    return res;
}
void check(bool cond, int res, string dbg = "") {
    if (!cond) exit(wrong(dbg, res));
}

int main(int argc, char** argv) {
    if(argc <= 3) {
        return IE;
    }
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "r");
    FILE* judge = fopen(argv[3], "r");

    return WA;
}