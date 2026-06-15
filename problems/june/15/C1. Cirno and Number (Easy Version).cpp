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
    ll a; int n; cin >> a >> n;
    vi d(n); fin(it, d) cin >> it;
    i128 aa = a, d1 = 0, d2 = 0;

    string st = to_string(a);
    int s = st.size();
    sort(all(d));

    fr(i, 0, s + 1) {
        d1 = d1 * 10 + (i128)d.front();
    }

    fr(i, 0, s - 1) {
        d2 = d2 * 10 + (i128)d.back();
    }

    if (n == 10) {
        quit(0);
    }

    auto abbs = [&](i128 a) -> i128 {
        return (a > 0 ? a : a * -1);
    };

    if (n == 1) {
        i128 res = 0;
        fr(i, 0, s) res = res * 10 + d.front();
        res = abbs(res - aa);
        quitv(((ll)res));
    }

    i128 ans = abbs(d1 - aa);
    if (s > 1) ans = min(ans, abbs(d2 - aa));
    i128 bs = -1;
    auto dfs = [&](auto& self, int idx, bool is_less, bool is_greater, i128 cn) -> void {
        if (idx == s) {
            if (bs == -1 || abbs(cn - aa) < abbs(bs - aa)) {
                bs = cn;
            }
            return;
        }

        if (is_less) {
            self(self, idx + 1, true, false, cn * 10 + d.back());
            return;
        }
        if (is_greater) {
            self(self, idx + 1, false, true, cn * 10 + d.front());
            return;
        }

        int td = st[idx] - '0';

        fin(digit, d) {
            if (idx == 0 && digit == 0 && s > 1) continue;

            if (digit < td) {
                self(self, idx + 1, true, false, cn * 10 + digit);
            } else if (digit == td) {
                self(self, idx + 1, false, false, cn * 10 + digit);
            } else {
                self(self, idx + 1, false, true, cn * 10 + digit);
            }
        }
    };

    dfs(dfs, 0, false, false, 0);

    if (bs != -1) {
        ans = min(ans, abbs(bs - aa));
    }

    show((ll)ans);
}

int main() {
    fio;
    mcase;
}


