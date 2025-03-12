struct Edge {
    int u, v, weight;
};

// Comparator to sort edges by weight
bool compare(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// this function will return the total weight of the minimum spanning tree
int kruskal(int n, vector<Edge>& edges) {
    // use atcoder::dsu to check for cycles
    dsu uf(n);
    // sort edges by weight (smallest to largest)
    sort(edges.begin(), edges.end(), compare);

    int total_weight = 0;

    // add edges to the minimum spanning tree unless this causes a cycle (i.e. no longer a tree)
    for (const auto& edge : edges) {
        if (!uf.same(edge.u, edge.v)) {
            uf.merge(edge.u, edge.v);
            total_weight += edge.weight;
            cout << "Edge added: (" << edge.u << ", " << edge.v << ") with weight " << edge.weight << "\n";
        }
    }

    return total_weight;
}