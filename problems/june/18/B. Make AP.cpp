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
    ll a, b, c; cin >> a >> b >> c;

    auto can = [&](ll diff) {
        if (diff < 0) return false;
        if (b - a == diff) {
            int nc = b + diff;
            if (a <= b && b <= nc && nc % c == 0) return true;
        }

        if (c - b == diff) {
            int na = b - diff;
            if (na <= b && b <= c && na % a == 0) return true;
        }


        if (c - 2 * diff == a) {
            int nb = c - diff;
            if (a <= nb && nb <= c && nb % b == 0) return true;
        }

        return false;
    };

    bool ok = can(b - a) || can(c - b) || can((c - a) / 2);
    swap(a, c);
    ok = ok || can(b - a) || can(c - b) || can((c - a) / 2);
    cani(ok);
}

int main() {
    fio;
    mcase;
}


