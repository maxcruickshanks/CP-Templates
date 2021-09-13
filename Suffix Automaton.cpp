#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int MM = 1e5 + 5;
vector<int> adj[MM];
struct node { int len = 0, pa = -1; unordered_map<char, int> nxt; };
struct SAM {
    vector<node> st; int last = 0;
    SAM() { st.push_back(node()); }
    void extend(int c) {
        int np = st.size(), p = last; st.push_back(node());
        st[np].len = st[p].len + 1;
        for (; p != -1 && !st[p].nxt.count(c); p = st[p].pa) st[p].nxt[c] = np;
        if (p == -1) st[np].pa = 0;
        else {
            int q = st[p].nxt[c];
            if (st[p].len + 1 == st[q].len) st[np].pa = q;
            else {
                int cl = st.size(); st.push_back(st[q]);
                st[cl].len = st[p].len + 1;
                for (; p != -1 && st[p].nxt[c] == q; p = st[p].pa) st[p].nxt[c] = cl;
                st[np].pa = st[q].pa = cl;
            }
        }
        last = np;
    }
    int dfs(int u) {
        int cnt = (u) ? st[u].len - st[st[u].pa].len : 0;
        for (int v : adj[u]) cnt += dfs(v);
        return cnt;
    }
    int countDistinctSubstr() {
        //getParentTree();
        //return dfs(0);
        int cnt = 0;
        for (int i = 1; i < st.size(); i++) cnt += st[i].len - st[st[i].pa].len;
        return cnt;
    }
    void getParentTree() {
        for (int i = 1; i < st.size(); i++) adj[st[i].pa].push_back(i);
    }
};
SAM sam;
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    string s; cin >> s;
    sam = SAM();
    for (char c : s) sam.extend(c);
    cout << sam.countDistinctSubstr() + 1 << "\n";
}