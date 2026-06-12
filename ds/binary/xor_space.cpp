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

