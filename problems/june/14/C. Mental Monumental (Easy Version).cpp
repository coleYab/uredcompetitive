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
    int n; cin >> n; vi a(n); fin(it, a) cin >> it;

    sort(all(a));
    auto can = [&](int x) {
        vi ok(x + 1, false);
        vi b;
        fin(it, a) if (it > x || ok[it]) b.pb(it); else ok[it] += 1;
        int l = 0;
        fr(i, 0, x + 1) {
            if (ok[i]) continue;
            while (l < sz(b)) {
                int c = b[l] / 2 + (b[l] & 1 ? 0 : -1);
                if (c >= i) break
                else l++;
            }

            if (l >= sz(b)) return false;

            l++;
            ok[i] = true;
        }

        return true;
    };


    int l = 0, r = n + 10, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (can(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    show(ans + 1);
}

int main() {
    fio;
    mcase;
}


