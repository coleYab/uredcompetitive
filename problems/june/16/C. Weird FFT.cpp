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

namespace math {
    using cd = complex<double>;
    using vcd = vector<cd>;

    constexpr double PI = acos(-1);

    void fft(vcd &a, bool invert = false) {
        int n = (int)a.size();

        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            while (j & bit) {
                j ^= bit;
                bit >>= 1;
            }
            j ^= bit;

            if (i < j)
                swap(a[i], a[j]);
        }

        for (int len = 2; len <= n; len <<= 1) {
            double ang = 2 * PI / len * (invert ? -1 : 1);
            cd wlen(cos(ang), sin(ang));

            for (int i = 0; i < n; i += len) {
                cd w(1);

                for (int j = 0; j < len / 2; j++) {
                    cd u = a[i + j];
                    cd v = a[i + j + len / 2] * w;

                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;

                    w *= wlen;
                }
            }
        }

        if (invert) {
            for (cd &x : a)
                x /= n;
        }
    }

    vector<long long> polymul(const vector<int> &a,
                              const vector<int> &b) {
        int n = 1;
        while (n < (int)a.size() + (int)b.size())
            n <<= 1;

        vcd fa(n), fb(n);

        for (int i = 0; i < (int)a.size(); i++)
            fa[i] = a[i];

        for (int i = 0; i < (int)b.size(); i++)
            fb[i] = b[i];

        fft(fa);
        fft(fb);

        for (int i = 0; i < n; i++)
            fa[i] *= fb[i];

        fft(fa, true);

        vector<long long> res(a.size() + b.size() - 1);

        for (int i = 0; i < (int)res.size(); i++)
            res[i] = llround(fa[i].real());

        return res;
    }
}


void solve() {
    int n; cin >> n; vi a(n); fin(it, a) cin >> it;
    int m; cin >> m; vi b(m); fin(it, b) cin >> it;

    vll res = math::polymul(a, b);
    vll ans;
    fr(i, 0, n + m - 1) {
        int cur = (i - 1) / 2;
        if (i == 0) ans.pb(0);
        else ans.pb(res[cur]);
    }
    cout << endl;
    print(res);
    print(ans);
}

int main() {
    fio;
    scase;
}


