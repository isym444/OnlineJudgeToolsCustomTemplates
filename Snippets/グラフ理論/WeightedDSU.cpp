// Weighted UnionFind
template <class S> struct WeightedUnionFind {
    //par for parent i.e. representative node of set (initially itself), size of set a node belongs to (only if node the root of that set) but n.b. count() returns appropriately
    std::vector<int> par, size;
    //pot stores the potential/weight of each element relative to the root of its set i.e. the distance to the root of the set for each node (given the weights of the edges)
    std::vector<S> pot;
    WeightedUnionFind(int N = 0) : par(N), size(N, 1), pot(N) {
        std::iota(par.begin(), par.end(), 0);
    }
    //finds the root of the set containing x
    int find(int x) {
        if (par[x] != x) {
            int r = find(par[x]);
            pot[x] = pot[x] + pot[par[x]], par[x] = r;
        }
        return par[x];
    }
    //unites sets containing s & t with a relative difference rel_diff and checks for contradictions
    bool unite(int s, int t, S rel_diff) {
        // Relate s and t by f[t] = f[s] + rel_diff
        // Return false if contradiction happens.
        rel_diff = rel_diff + weight(s) + (-weight(t));
        // If already in the same set, check for a contradiction in pre-existing weights and if so, return false else return true
        if ((s = find(s)) == (t = find(t))) return rel_diff == 0;
        if (size[s] < size[t]) std::swap(s, t), rel_diff = -rel_diff;
        par[t] = s, size[s] += size[t], pot[t] = rel_diff;
        return true;
    }
    //returns weight of x relative to root of its set
    S weight(int x) { return find(x), pot[x]; }
    //returns difference in potential between t and s N.B. that ORDER MATTERS e.g. if want coordinates, put the node at 0,0 as first argument i.e. s
    S diff(int s, int t) { return weight(t) + (-weight(s)); } // return f[t] - f[s]
    //returns size of set containing x
    int count(int x) { return size[find(x)]; }
    //checks if s and t are in same set
    bool same(int s, int t) { return find(s) == find(t); }
};