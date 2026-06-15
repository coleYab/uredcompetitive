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
    vi ods, evs; fin(it, a) if (it & 1) ods.pb(it); else evs.pb(it);
    int omx = ninf, omn = inf, emx = ninf, emn = inf;
    fin(it, ods) {
        omn = min(omn, it);
        omx = max(omx, it);
    }

    fin(it, evs) {
        emn = min(emn, it);
        emx = max(emx, it);
    }

    bool ok = true;

    if (sz(evs)) {
        int cmx = evs[0];
        fr(i, 1, sz(evs)) {
            if (cmx <= evs[i]) {
                cmx = evs[i];
                continue;
            }

            if (omn < evs[i] && omn < cmx) continue;
            if (omx > evs[i] && omx > cmx) continue;
            ok = false;
        }


    }


    if (sz(ods)) {
        int cmx = ods[0];
        fr(i, 1, sz(ods)) {
            if (cmx <= ods[i]) {
                cmx = ods[i];
                continue;
            }

            if (emn < ods[i] && emn < cmx) continue;
            if (emx > ods[i] && emx > cmx) continue;
            ok = false;
        }
    }

    cani(ok);
}

int main() {
    fio;
    mcase;
}
