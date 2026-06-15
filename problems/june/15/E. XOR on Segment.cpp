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

struct seg_lazy {
    // START: PLEASE MODIFY SOME DETAILS HERE
    struct node {
        ll lazy;
        int cnt;
        ll ans;
    };

    node merge(const node &left, const node &right) {
        return { noop, left.cnt + right.cnt, left.ans + right.ans };
    }

    const ll noop = 0;
    const ll cur = 0;
    node zero {noop, 0, cur};

    node apply(node now, ll val) {
        if (val == noop) return now;
        if (now.cnt == 0) return now;

        now.lazy ^= val; // 1 or 0
        now.ans = now.cnt - now.ans;

        return now;
    }

    // END: PLEASE MODIFY SOME DETAILS HERE
    void restore(node &now) {
        now.lazy = noop;
    }

    int size;
    vector<node> tree;
    void push_down(int x, int lx, int rx) {
        if (rx - lx == 1) return;
        if (tree[x].lazy == noop) return;
        tree[2 * x + 1] = apply(tree[2 * x + 1], tree[x].lazy);
        tree[2 * x + 2] = apply(tree[2 * x + 2], tree[x].lazy);
        restore(tree[x]);
    }

    void init(int n, int x, int lx, int rx) {
        tree[x].lazy = noop;
        if (lx < n) tree[x].ans = 0;
        tree[x].cnt = min(rx, n) - lx;
        if (tree[x].cnt < 0) tree[x].cnt = 0;
        if (rx - lx == 1) return;
        int mid = (lx + rx) / 2;
        init(n, 2 * x + 1, lx, mid);
        init(n, 2 * x + 2, mid, rx);
    }

    seg_lazy(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, zero);
        init(n, 0, 0, size);
    }

    // Point assign
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    void set(int id, int v, int x, int lx, int rx) {
        push_down(x, lx, rx);
        if (rx - lx == 1) {
            // tree[x].set(v);
            return;
        }

        int mid = (lx + rx) / 2;
        if (id < mid) set(id, v, 2 * x + 1, lx, mid);
        else          set(id, v, 2 * x + 2, mid, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void modify(int l, int r, int v) {
        modify(l, r, v, 0, 0, size);
    }

    void modify(int l, int r, int v, int x, int lx, int rx) {
        push_down(x, lx, rx);
        if (l >= rx || lx >= r) return;
        if (l <= lx && rx <= r) {
            tree[x] = apply(tree[x], v);
            return;
        }

        int mid = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, mid);
        modify(l, r, v, 2 * x + 2, mid, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    node get(int l, int r) {
        return get(l, r, 0, 0, size);
    }

    node get(int l, int r, int x, int lx, int rx) {
        push_down(x, lx, rx);
        if (l >= rx || lx >= r) return zero;
        if (l <= lx && rx <= r) return tree[x];
        int mid = (lx + rx) / 2;
        return merge(get(l, r, 2 * x + 1, lx, mid), get(l, r, 2 * x + 2, mid, rx));
    }
};


constexpr int mxn = 30;
void solve() {
    int n; cin >> n;
    vll a(n); fin(it, a) cin >> it;
    vector<seg_lazy> seg(mxn, n);
    fr(i, 0, n) fr(j, 0, mxn) {
        int x = a[i];
        if ((x >> j) & 1) seg[j].modify(i, i + 1, 1);
    }
    int m; cin >> m;
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            ll ans = 0;
            fr(i, 0, mxn) {
                int cur = seg[i].get(l - 1, r).ans;
                ans += (1LL<<i) * cur;
            }
            show(ans);
        } else {
            int l, r, k; cin >> l >> r >> k;
            fr(i, 0, mxn) {
                if ((k >> i) & 1) {
                    seg[i].modify(l - 1, r, 1);
                }
            }
        }
    }

}

int main() {
    fio;
    scase;
}


