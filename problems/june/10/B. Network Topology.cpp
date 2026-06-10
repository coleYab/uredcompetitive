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
#define tag(x) cout << #x << '\n'

void solve() {
    int n, m; cin >> n >> m;
    vi deg(n);
    fr(i, 0, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        deg[u]++, deg[v]++;
    }

    bool ring = 1;
    fr(i, 0, n) {
        if (deg[i] != 2) ring = 0;
    }
    if (ring) quit(ring topology);
    int two = 0, one = 0, nmin = 0;
    fr(i, 0, n) {
        if (deg[i] == 2) two++;
        else if (deg[i] == 1)one++;
        if (deg[i] == n - 1) nmin++;
    }

    bool bus = one == 2 && two == (n - 2);
    if (bus) quit(bus topology);

    bool star = (one == (n - 1)) && nmin == 1;
    if (star) quit(star topology);

    tag(unknown topology);
}

int main() {
    fio;
    scase;
}


