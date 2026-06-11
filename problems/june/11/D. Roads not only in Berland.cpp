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
        u = find(u), v = find(v);
        if (u == v) return false;
        par[v] += par[u]; par[u] = v;
        return true;
    }
};

void solve() {
    int n; cin >> n;
    dsu_t dsu(n);
    vpii edges;
    fr(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        u--, v--;
        if (dsu.merge(u, v)) continue;
        edges.pb({u + 1, v + 1});
    }

    vi pars;
    fr(i, 0, n) if (dsu.par[i] < 0) pars.pb(i + 1);
    show(sz(edges));
    assert(sz(edges) == sz(pars) - 1);
    fr(i, 0, sz(edges)) {
        cout << edges[i].ff << " " << edges[i].ss << " " << pars[i] << " " << pars[i + 1] << endl;
    }
}

int main() {
    fio;
    scase;
}


