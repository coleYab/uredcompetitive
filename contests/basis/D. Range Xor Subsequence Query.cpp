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
#define cani(x) show(((x) ? "Yes" : "No"))
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

struct seg_tree {
    // BEGIN: HERE IS CUSTOM CONFIGURATIONS
    struct node {
        lb_t lb;
        void set(ll x) { lb.insert(x); }
    };

    node zero{
    };

    node merge(node l, node r) {
        node res;
        res.lb = l.lb;
        r.lb.rebuild();
        fin(it, r.lb.ordered) res.lb.insert(it);
        return res;
    }

    // END: HERE IS CUSTOM CONFIGURATIONS
    int size;
    vector<node> tree;
    seg_tree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2 * size, zero);
    }

    node get(int l, int r) {
        return get(l, r, 0, 0, size);
    }

    node get(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return zero;
        if (l <= lx && rx <= r) return tree[x];
        int mid = (lx + rx) / 2;
        return merge(get(l, r, 2 * x + 1, lx, mid), get(l, r, 2 * x + 2, mid, rx));
    }

    void set(int id, ll val) {
        set(id, val, 0, 0, size);
    }

    void set(int id, ll val, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x].set(val);
            return;
        }
        int mid = (lx + rx) / 2;
        if (id < mid) set(id, val, 2 * x + 1, lx, mid);
        else set(id, val, 2 * x + 2, mid, rx);
        tree[x] = merge(tree[2 * x+ 1], tree[2 * x + 2]);
    }
};

struct rmq_t {
    int n, LOG;
    vector<vector<lb_t>> st;
    vi lg;

    rmq_t(const vll& a) {
        n = a.size();
        lg.resize(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        LOG = lg[n] + 1;
        st.assign(LOG, vector<lb_t>(n));

        // k = 0
        for (int i = 0; i < n; i++)
            st[0][i].insert(a[i]);

        // build
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = st[k - 1][i + (1 << (k - 1))];
                st[k - 1][i].rebuild();
                fin(it, st[k - 1][i].ordered) st[k][i].insert(it);
            }
        }
    }

    bool query(int l, int r, ll x) {
        r--;
        int k = lg[r - l + 1];
        if (st[k][l].can(x) || st[k][r - (1<<k)+1].can(x)) return true;
        lb_t res = st[k][r-(1<<k)+1];
        st[k][l].rebuild();
        fin(it, st[k][l].ordered) res.insert(it);
        return res.can(x);
    }
};

void solve() {
    int n; cin >> n; vll a(n); fin(it, a) cin >> it;
    // seg_tree st(n); fr(i, 0, n) st.set(i, a[i]);
    rmq_t rmq(a);

    int m; cin >> m;
    while(m--) {
        int l,r;ll x; cin >>l>>r>>x;
        cani(rmq.query(l - 1, r, x));
    }
}

int main() {
    fio;
    scase;
}


