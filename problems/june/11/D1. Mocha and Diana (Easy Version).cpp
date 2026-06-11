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
#define tag(x) cout << #x << endl

struct dsu_t {
    vi par;
    dsu_t(int n) : par(n, -1) { }
    int find(int x) { if (par[x] < 0) return x; return par[x] = find(par[x]); }
    bool merge(int u, int v) {
        u = find(u), v = find(v); if (u == v) return false;
        par[u] += par[v]; par[v] = u;
        return true;
    }

    bool conn(int u, int v) {
        return find(u) == find(v);
    }
};

void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    dsu_t f1(n), f2(n);
    fr(i, 0, m1) {
        int u, v; cin >> u >> v;
        u--, v--;
        f1.merge(u, v);
    }

    fr(i, 0, m2) {
        int u, v; cin >> u >> v;
        u--, v--;
        f2.merge(u, v);
    }

    vpii ans;
    int j  = 0;
    fr(i, 0, n) {
        if (f1.find(i) != f1.find(j) && f2.find(i) != f2.find(j)) {
            ans.pb({i, j});
            f1.merge(i, j);
            f2.merge(i, j);
        }
    }

    show(sz(ans));
    fin(it, ans) cout<<it.ff+1 <<" " <<it.ss+1 << endl;
}

int main() {
    fio;
    scase;
}


