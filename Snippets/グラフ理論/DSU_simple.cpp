// UnionFind Tree (0-indexed), based on size of each disjoint set
// find, unite, count, same: O(1)
struct UnionFind {
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
    vector<ll> getLeaders() {
        set<ll> leaders;
        for (int i = 0; i < par.size(); i++) {
            leaders.insert(find(i));
        }
        return vector<ll>(leaders.begin(), leaders.end());
    } 
};
