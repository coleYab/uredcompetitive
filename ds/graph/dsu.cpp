struct dsu_t {
    vi par;
    int csize;
    dsu_t(int n) : par(n, -1), csize(n) { }
    int find(int x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        par[u] += par[v];
        par[v] = u;
        csize--;
        return true;
    }

    bool conn(int u, int v) {
        return find(u) == find(v);
    }
};
