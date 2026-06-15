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

void solve() {
    int n; cin >> n;
    vvi g(n); fin(it, g) { it.resize(n); fin(jt, it) cin >> jt; }
    vvi dp(n, vi(n, -1));
    vector<vpii> bef(n + 1, vpii(n + 1, {-1, -1}));
    vvi dir(n + 1, vi(n + 1, -1));

    fr(i, 0, n) {
        fr(j, 0, n) {
            if (i) {
                dp[i][j] = dp[i - 1][j] + g[i][j] == 0;
                bef[i][j] = {i - 1, j};
                dir[i][j] = 'D';
            }

            if (j) {
                int cur = dp[i][j];
                int now = dp[i][j - 1] + g[i][j] == 0;
                if (cur == -1 || cur > now) {
                    dp[i][j] = cur;
                    bef[i][j] = {i, j - 1};
                    dir[i][j] = 'R';
                }
            }
        }
    }

    fin(it, dir) { print(it); }
    int x = n - 1, y = n - 1;
    vpii ans;
    while (x != -1) {
        ans.pb({x, y});
        x = bef[x][y].ff, y = bef[x][y].ss;
        if (x == 0 && y == 0) break;
    }
    fin(it, ans) cout << it.ff << " " << it.ss << endl;
}

int main() {
    fio;
    scase;
}


