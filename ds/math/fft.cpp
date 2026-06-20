namespace math {
    using cd = complex<double>;
    using vcd = vector<cd>;

    const double PI = acos(-1.0);
    const int N = 1 << 21;
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
            for (; j & bit; bit >>= 1) j ^= bit;
            j ^= bit;
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

    vi polymul(const vi &a, const vi &b) {
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

        vi r(t);
        frn(i, t) r[i] = round(aa[i].imag() / 2.0);
        return r;
    }
};
