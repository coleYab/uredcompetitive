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

using ar = array<int, 3>;

struct dsu_t {
    vi par;
    ll res = 0;
    dsu_t(int n) {
        par.assign(n, -1);
    }

    int find(int x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;

        ll us = -par[u], vs = -par[v];
        res -= ((us * (us -  1)) / 2);
        res -= ((vs * (vs -  1)) / 2);
        us += vs;
        res += ((us * (us - 1)) / 2);
        par[u] += par[v]; par[v] = u;
        return true;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<ar> eds;
    fr(i, 0, n - 1) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        eds.pb({u, v, w});
    }

    sort(all(eds), [&](const ar &l, const ar &r) {
            return l[2] < r[2];
    });

    vi q(m); fin(it, q) cin >> it;
    vi ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&](int l, int r) { return q[l] < q[r];  });

    vll ans(m);
    dsu_t dsu(n);
    int lw = 0;
    fin(it, ord) {
        int cw = q[it];
        while (lw < (n - 1) && eds[lw][2] <= cw) {
            dsu.merge(eds[lw][0], eds[lw][1]);
            lw++;
        }
        ans[it] = dsu.res;
    }

    print(ans);
}

int main() {
    fio;
    scase;
}


