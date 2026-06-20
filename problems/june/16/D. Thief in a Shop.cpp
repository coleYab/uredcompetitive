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

    const double PI = acos(-1.0);
    const int N = 1 << 25;
    vcd w(N), aa(N);
    bool init = false;

    void setup() {
        if (init) return;
        frn(i, N) w[i] = cd(cos(2 * PI * i / N), sin(2 * PI * i / N));
        init = true;
    }

    void fft(vcd &a, int n, bool inv) {
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1) j ^= bit; j ^= bit;
            if (i < j) swap(a[i], a[j]);
        }

        for (int l = 2; l <= n; l <<= 1) {
            int h = l >> 1;
            int step = N / l;
            for (int i = 0; i < n; i += l) {
                fr(j, 0, h) {
                    int idx = j * step;
                    if (inv && idx > 0) idx = N - idx;
                    cd u = a[i + j], v = a[i + j + h] * w[idx];
                    a[i + j] = u + v;
                    a[i + j + h] = u - v;
                }
            }
        }

        if (inv) {
            frn(i, n) a[i] /= n;
        }
    }

    vll polymul(const vll &a, const vll &b) {
        if (a.empty() || b.empty()) return {};
        setup();

        int m = 1, t = sz(a) + sz(b) - 1;
        while (m < t) m <<= 1;

        fill(aa.begin(), aa.begin() + m, cd(0));

        frn(i, sz(a)) aa[i].real(a[i]);
        frn(i, sz(b)) aa[i].imag(b[i]);

        fft(aa, m, false);
        frn(i, m) aa[i] *= aa[i];
        fft(aa, m, true);

        vll r(t);
        frn(i, t) r[i] = llround(aa[i].imag() / 2.0);
        return r;
    }
};


void solve() {
    int n, k = (1<<12)-1; cin >> n >> k;
    k = (1<<9) -1;
    vll a(n); fin(it, a) cin >> it;

    vll b(1e7+1, rand() % 28);

    auto res = math::polymul(b, b);
    show(sz(res));
}

int main() {
    fio;
    scase;
}


