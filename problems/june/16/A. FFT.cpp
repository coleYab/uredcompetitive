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


    constexpr double PI = atan2(0, -1);
    vcd fft(const vcd &p) {
        const int n = sz(p);
        const int half = n / 2;
        assert(__builtin_popcount(n) == 1);

        if (n == 1) return p;

        vcd even(half), odd(half);
        fr(i, 0, half) even[i] = p[2 * i], odd[i] = p[2 * i + 1];

        vcd reven = fft(even), rodd = fft(odd), res(n);

        fr(i, 0, half) {
            cd wi(cos(2 * PI * i / n), sin(2 * PI * i / n));
            res[i] = reven[i] + wi * rodd[i];
            res[half + i] = reven[i] - wi * rodd[i];
        }

        return res;
    }

    vcd ifft(vcd p) {
        const int n = sz(p);
        int l = 1, r = n - 1;
        while (l <= r) {
            swap(p[l], p[r]);
            l++, r--;
        }

        fin(it, p) it /= n;

        return p;
    }

    vcd polymul(const vi &a, const vi &b) {
        int rsz = 1;
        while (rsz < (sz(a) + sz(b) - 1)) rsz *= 2;
        vcd aa(rsz), bb(rsz);
        copy(all(a), aa.begin());
        copy(all(b), bb.begin());

        vcd resa = fft(aa), resb = fft(bb);
        fr(i, 0, rsz) resa[i] *= resb[i];
        return ifft(fft(resa));
    }
};

void solve() {
    int n; cin >> n; vi a(n); fin(it, a) cin >> it;
    int m; cin >> m; vi b(m); fin(it, b) cin >> it;
    auto res = math::polymul(a, b);
    fr(i, 0, n + m - 1) cout << (ll)(res[i].real() + 0.5) << " ";
    cout << endl;
}

int main() {
    fio;
    scase;
}


