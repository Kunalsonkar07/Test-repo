class UnionFind {
private:
    vector<int> par, sz;
public:
    UnionFind(int n) {
        par.resize(n);
        sz.assign(n, 1);
        iota(par.begin(), par.end(), 0);
    }
    int find(int u) {
        if (par[u] != u) par[u] = find(par[u]);
        return par[u];
    }
    int join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return u;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return u;
    }
};
