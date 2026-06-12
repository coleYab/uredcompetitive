struct node_t {
    node_t *next[2];
    int cnt;
    bool is_end;

    node_t() : cnt(0), is_end(false) {
        next[0] = next[1] = nullptr;
    }
};

constexpr int mxb = 60;
struct trie_t {
    node_t *root;
    trie_t() { root = new node_t(); }
    void insert(ll x) {
        node_t *cur = root;
        ++cur->cnt;

        rfr(i, mxb, 0) {
            int nd = (x >> i) & 1;
            if (!cur->next[nd]) {
                cur->next[nd] = new node_t();
            }
            cur = cur->next[nd];
            ++cur->cnt;
        }

        cur->is_end = true;
    }
};
