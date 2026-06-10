#include <bits/stdc++.h>
#include <cassert>

using namespace std;

#define fio ios::sync_with_stdio(false); cin.tie(nullptr);
#define rfile(x) freopen(x, "r", stdin);
#define wfile(x) freopen(x, "w", stdout);
#define fix(x) cout << fixed << setprecision(x);

#define scase solve();
#define mcase int t; cin >> t; while(t--) solve();

using ll = long long; using ld = long double;
using ull = unsigned long long; using pii = pair<int, int>;
using pll = pair<ll, ll>; using vll = vector<ll>;
using vi = vector<int>; using vpii = vector<pii>;
using vpll = vector<pll>; using vvi = vector<vi>;
using vvl = vector<vll>; using i128 = __int128_t;

constexpr int inf = numeric_limits<int>::max();
constexpr int ninf = numeric_limits<int>::min();

#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

#define fr(i, a, b) for (int i = (a); i < (b); ++i)
#define frn(i, n) fr(i, 0, n)
#define rfr(i, a, b) for (int i = (a); i >= (b); --i)
#define fin(a, b) for (auto& a : b)
#define print(a) for (auto &it : a) cout << it << " "; cout << '\n';
#define show(x) cout << (x) << '\n'
#define cani(x) show(((x) ? "YES" : "NO"))
#define quit(x) { cout << #x << '\n'; return; }
#define quitv(x) { cout << x << '\n'; return; }

void solve() {
    int n; cin >> n;
    map<string, vector<string>> adj;
    map<string, int> cnt;
    vector<string> sts;
    fr(i, 0, n) {
        string s, r, t; cin >> s >> r >> t;
        fin(it, s) it = tolower(it);
        fin(it, t) it = tolower(it);
        adj[t].pb(s);
        sts.pb(t);
        sts.pb(s);
        cnt[s]++;
    }


    function<void(string, string, int, int&)>  dfs = [&](string r, string f, int d, int &mxd) {
        mxd = max(d, mxd);
        fin(it, adj[r]) if (it != f) dfs(it, r, d + 1, mxd);
    };

    int ans = 0;
    fin(it, sts) if (cnt[it] == 0) dfs(it, it, 0, ans);
    show(ans + 1);
};

int main() {
    fio;
    scase;
}


