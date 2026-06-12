struct seg_tree {
    // BEGIN: HERE IS CUSTOM CONFIGURATIONS
    struct node {
    };

    node zero{
    };

    node merge(node l, node r) {
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

    void set(int id, int val) {
        set(id, val, 0, 0, size);
    }

    void set(int id, int val, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x].v = val;
            tree[x].c = 1;
            return;
        }
        int mid = (lx + rx) / 2;
        if (id < mid) set(id, val, 2 * x + 1, lx, mid);
        else set(id, val, 2 * x + 2, mid, rx);
        tree[x] = merge(tree[2 * x+ 1], tree[2 * x + 2]);
    }
};

