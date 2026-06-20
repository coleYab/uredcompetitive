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


constexpr int LOG = 60;
struct linear_basis_t {
    struct entry_t {
        ll val = 0;
        int time = -1;
    };

    entry_t basis[LOG + 1]{};
    vll ordered;

    int size = 0;
    int count = 0;

    bool insert(ll x) {
        return insert(x, count);
    }

    bool insert(ll x, int time) {
        ++count;
        rfr(i, LOG, 0) {
            if (!(x >> i & 1)) continue;

            if (basis[i].time == -1) {
                basis[i] = {x, time}; size++;
                return true;
            }

            if (basis[i].time < time) {
                swap(time, basis[i].time);
                swap(x, basis[i].val);
            }

            x ^= basis[i].val;
        }

        return false;
    }

    ll maxxor(int lid = 0) const {
        ll ans = 0;

        rfr(i, LOG, 0) {
            if (basis[i].time > lid) ans = max(ans, ans ^ basis[i].val);
        }

        return ans;
    }

    bool can(ll x) const {
        rfr(i, LOG, 0) {
            if (!(x >> i & 1)) continue;
            if (basis[i].time == -1) return false;
            x ^= basis[i].val;
        }

        return true;
    }

    void rebuild() {
        ordered.clear();
        entry_t tmp[LOG + 1];
        memcpy(tmp, basis, sizeof(basis));

        rfr(i, LOG, 0) {
            if (tmp[i].time == -1) continue;

            rfr(j, i - 1, 0) {
                if (tmp[j].time != -1 && (tmp[i].val >> j & 1)) {
                    tmp[i].val ^= tmp[j].val;
                }
            }
        }

        fr(i, 0, LOG + 1) {
            if (tmp[i].time != -1) {
                ordered.pb(tmp[i].val);
            }
        }
    }


    ll kth(ll k) const {
        if (size < 63 && k >= (1LL << size)) return -1;

        ll ans = 0;
        fr(i, 0, size) {
            if (k >> i & 1) ans ^= ordered[i];
        }

        return ans;
    }

    ll dupc() const {
        int freec = count - size;
        return (1LL << freec);
    }

    ll kth_dup(ll k) {
        int ku = (k / dupc());
        return kth(ku);
    }

    void clear() {
        fin(it, basis) {
            it = entry_t{};
        }
    }
};

using lb_t = linear_basis_t;

constexpr ll mod = (1e9+7);
ll poww(ll exp) {
    ll res = 1, b = 2;
    while(exp) {
        if (exp&1) res = ((i128) res * b) % mod;
        exp >>= 1;
        b = ((i128)b * b) % mod;
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(n); fin(it,a) cin >> it;
    lb_t lb;
    vector<vpii> qry(n);
    fr(i, 0, m) {
        int l, x; cin >> l >> x;
        qry[l - 1].pb({x, i});
    }

    vll ans(m);
    fr(i, 0, n) {
        lb.insert(a[i]);
        for(auto [x, y] : qry[i]) {
            if (lb.can(x)) ans[y] = poww(lb.count - lb.size);
        }
    }
    fin(it,ans)show(it);
}

int main() {
    fio;
    scase;
}


