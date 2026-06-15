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

const int mxn = 1e7+100;

int spf1[mxn];
int spf2[mxn];

void init() {
    fill(begin(spf1), end(spf1), -1);
    fill(begin(spf2), end(spf2), -1);
    fr(i, 2, mxn) {
        if (spf1[i] != -1) continue;
        spf1[i] = i;
        for(int j = i + i; j < mxn; j += i) {
            if (spf1[j] == -1) spf1[j] = i;
            else if (spf2[j] == -1) spf2[j] = i;
        }
    }
}

void solve() {
    init();
    int n; cin >> n;
    vi a1, a2;
    a1.reserve(n);
    a2.reserve(n);
    fr(i, 0, n) {
        int x; cin >> x;
        if (spf2[x] == -1) a1.pb(-1), a2.pb(-1);
        else a1.pb(spf1[x]), a2.pb(spf2[x]);
    }
    print(a1);
    print(a2);
}

int main() {
    fio;
    scase;
}


