struct seg_lazy {
    // START: PLEASE MODIFY SOME DETAILS HERE
    struct node {
        ll lazy;
        int cnt;
        ...
    };

    node merge(node left, node right) {
        ...
    }

    const ll noop = inf;
    const ll cur = 0;
    node zero {noop, 0, cur};

    node apply(node now, ll val) {
        if (val == noop) return now;
        if (now.cnt == 0) return now;
        ...
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

