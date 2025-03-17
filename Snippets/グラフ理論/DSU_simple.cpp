// UnionFind Tree (0-indexed), based on size of each disjoint set
// find, unite, count, same: O(1)
struct UnionFind {
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) { iota(par.begin(), par.end(), 0); }
    // find the representative (or leader) of the set to which a particular element belongs
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
    // vector<ll> getLeaders() {
    //     set<ll> leaders;
    //     for (int i = 0; i < par.size(); i++) {
    //         leaders.insert(find(i));
    //     }
    //     return vector<ll>(leaders.begin(), leaders.end());
    // } 
    // optimized getLeaders() O(N) vs O(NlogN above)
    vector<ll> getLeaders() {
        unordered_set<ll> leaders;
        for (int i = 0; i < par.size(); i++) {
            if (par[i] == i) {
                leaders.insert(i);  // Already a leader, no need to call find()
            } else {
                leaders.insert(find(i));  // Only compress path when necessary
            }
        }
        return vector<ll>(leaders.begin(), leaders.end());
    }
};

// par[i] stores the parent/leader of node i.
// If par[i] == i, then i is the root of its set, meaning it is the leader of the connected component
// Path compression is used in the find() function to flatten the structure for faster subsequent queries.
// i.e. the parent of each node is updated to the leader of the set to which it belongs (these are not immediately updated on merge operation for all nodes in a set)
// The find function with path compression only updates the par (parent) for the nodes along the path that was traversed during the search

// cou[i] stores the size of the set whose leader is i.
// i.e. only meaningful for nodes who are leaders
// When two sets are united using the unite() function, the size of the resulting set is updated accordingly.
// This array helps in efficiently keeping track of the sizes of sets, and it's also used for union by size optimization, where smaller sets are merged into larger ones to keep the tree shallow.

// Initially:
// par = {0, 1, 2, 3, 4} (each element is its own leader)
// cou = {1, 1, 1, 1, 1} (each set contains only one element)

// After uf.unite(0, 1);:
// par = {0, 0, 2, 3, 4} (0 is the leader of set {0, 1})
// cou = {2, 1, 1, 1, 1} (the set containing 0 now has size 2)

