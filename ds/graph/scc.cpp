
struct kosaraju_t {
    int n;
    vvi adj, radj;
    vi who;

    kosaraju_t(int n) : n(n), adj(n) {}
    void add_edge(int u, int v) {
        adj[u].pb(v);
        radj[v].pb(u);
    }

    stack<int> stk;
    void dfs1(int r, set<int> &seen) {
        seen.insert(r);
        fin(it, adj[r]) {
            if (seen.count(it)) continue;
            dfs1(it, seen);
        }
        stk.pb(it);
    }

    void dfs2(int r, int rep, set<int> &seen) {
        seen.insert(r);
        who[r] = rep;
        fin(it, radj[r]) {
            if (seen.count(it)) continue;
            dfs2(it, rep, seen);
        }
    }

    void init() {
        set<int> seen;
        stk.clear();
        fr(i, 0, n) {
            if (seen.count(i)) continue;
            dfs1(i, seen);
        }

        seen.clear();
        who.resize(n);
        int rep = 0;
        while (sz(stk)) {
            int top = stk.top(); stk.pop();
            if (seen.count(top)) continue;
            dfs2(top, rep++, seen);
        }
    }

    bool same(int u, int v) { return who[v] == who[u]; }
};
