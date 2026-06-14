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


struct seg_tree {
    // BEGIN: HERE IS CUSTOM CONFIGURATIONS
    struct node {
        ll val;
        ll pref;
        void set(int x) {
            pref += x;
            val = pref;
        }
    };

    node zero{
        1, 1
    };

    node merge(node l, node r) {
        return node{
            min(l.val, l.pref + r.val),
            l.pref + r.pref,
        };
    }

    // END: HERE IS CUSTOM CONFIGURATIONS
    int size;
    vector<node> tree;
    seg_tree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2 * size);
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

    void set(int id, int val) {
        set(id, val, 0, 0, size);
    }

    void set(int id, int val, int x, int lx, int rx) {
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

void solve() {
    int n; cin >> n; vi a(n); fin(it, a) cin >> it;
    vi ans; int mex = 0;
    seg_tree st(n + 10);
    set<int> fix; multiset<int> have;

    fr(i, 0, st.size) st.set(i, 1);

    auto gid = [&](int cur) {
        return min(n + 9, (cur - 1) / 2);
    };

    auto can = [&](int cur, int id) -> bool {
        if (!fix.count(cur)) {
            auto now = have.find(cur);
            if (now != have.end()) {
                fix.insert(cur);
                st.set(cur, -1);
                have.erase(have.find(cur));
                st.set(id, 1);
            }
        }

        int wst = max(0LL, -st.tree[0].val);
        return (cur + 1 - sz(fix)) <= (sz(have) - wst);
    };

    fr(i, 0, n) {
        int cur = a[i], id = gid(cur);
        if (cur < mex && !fix.count(cur)) {
            fix.insert(cur);
            st.set(cur, -1);
        } else have.insert(cur), st.set(id, -1);
        while (can(mex, gid(mex))) mex++;
        ans.pb(mex);
    }

    print(ans);
}

int main() {
    fio;
    mcase;
}


