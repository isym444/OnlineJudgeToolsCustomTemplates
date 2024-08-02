vector<ll> parent; // To store parent information
//visited nodes
vector<bool> vis;
//bool vis[61][61][61][61]={0};
map<ll,ll> depth;

//initialize graph as adjacency list
vector<vector<ll> > g;
//initialize weighted graph as adjacency list
vector<vector<pair<ll,ll>>> wg;
//for building the adjacency list by adding edges info
ll totalEdges = 0;
void edge(ll originNode, ll destNode)
{
    g[originNode].pb(destNode);
    totalEdges++;
 
    // for undirected graph e.g. tree, add this line:
    g[destNode].pb(originNode);
}

void edge(ll originNode, ll destNode, ll weight){
    wg[originNode].emplace_back(destNode, weight);
    totalEdges++;
    // For an undirected graph e.g., tree, add this line:
    wg[destNode].emplace_back(originNode, weight);
}

//returns vector where each index is the shortest distance between the start node and node i
vector<ll> dijkstra(ll start) {
    vector<ll> dist(wg.size(), INF);  // Distance from start to each node
    //arguments: 1) type of elements pq will store 2) underlying container to be used by pq 
    //3) comparison function to specify order of elements in pq (default is less with largest element at top i.e. max-heap vs min-heap below)
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[start] = 0;
    pq.push({0, start});  // {distance, node}

    while (!pq.empty()) {
        //cerr << "pq" << pq << endl;
        ll currentDist = pq.top().first;
        ll currentNode = pq.top().second;
        pq.pop();

        // If the distance in priority queue is larger, we have already found a better path
        if (currentDist > dist[currentNode]) {
            continue;
        }
        /* Optimization to try if TLEing instead of if statement above
        if (cdist != dist[node]) { continue; }*/
    
        for (auto &neighbor : wg[currentNode]) {
            ll nextNode = neighbor.first;
            ll weight = neighbor.second;
            ll newDist = currentDist + weight;

            if (newDist < dist[nextNode]) {
                dist[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }

    return dist;
}

//Bellman Ford Graph: L node, R node, weight of edge between L&R
vector<tuple<int, int, ll>> bfg;

vector<ll> bellmanDistances;
// Function to run Bellman-Ford algorithm given start node and # vertices, saves min distances in bellmanDistances vector
bool bellmanFord(ll start, ll V) {
    vector<ll> distance(V, INF);
    bellmanDistances.resize(V, INF);
    bellmanDistances[start] = 0;
    ll a,b,w;
    for (ll i = 1; i <= V - 1; i++) {
        for (const auto& e : bfg) {
            tie(a, b, w) = e;
            bellmanDistances[b]=min(bellmanDistances[b],bellmanDistances[a]+w);
            /* if (bellmanDistances[a] + w < bellmanDistances[b]) {
                bellmanDistances[b] = bellmanDistances[a] + w;
            } */
        }
    }

    // Check for negative-weight cycles (negative sum of edges in a cycle)
    for (const auto& e : bfg) {
        tie(a, b, w) = e;
        if (bellmanDistances[a] + w < bellmanDistances[b]) {
            cout << "Graph contains negative weight cycle" << endl;
            return false;
        }
    }

/*     // Print the distances
    for (int i = 0; i < V; i++)
        cout << "Distance from " << start << " to " << i << " is " << (distance[i] == INF ? "INF" : to_string(distance[i])) << endl;
 */
    return true;
}


//traverse a graph using bfs from the specified start node to all other nodes, in the process printing the order the nodes are visited in
void bfs(ll start)
{
    queue<ll> q;
 
    q.push(start);
    vis[start] = true;
    depth[start] = 1; // Depth of starting node is 1
    //If want first time something happens/node reached then break when that happens
    while (!q.empty()) {
        ll f = q.front();
        q.pop();
 
        cerr << f << " ";
        
        // Enqueue all adjacent of f and mark them visited 
        ll counter = 0;
        for (auto i = g[f].begin(); i != g[f].end(); i++) {
            if (!vis[*i]) {
                counter++;
                q.push(*i);
                vis[*i] = true;
                depth[*i] = depth[f] + 1; // Set the depth of the neighboring node
            }
        }
        /* if(counter==0){
            cerr << "depths to leafs: " << depth[f] << endl;
        } */
    }
}

//bfs function returning vector with the shortest paths from start node to every other node
vector<ll> bfs_shortest_paths(ll start) {
    vector<long long> distances(g.size()+1, -1);
    queue<int> q;

    distances[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : g[node]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return distances;
}

//return a vector containing bfs path from start to end nodes specified
//don't forget to initialize parent with parent.assign(n+1, -1);
vector<ll> bfs(ll start, ll end) {
    queue<ll> q;
    q.push(start);
    vis[start] = true;
    parent[start] = -1; // Start node has no parent

    while (!q.empty()) {
        ll f = q.front();
        q.pop();

        if (f == end) break; // Stop if we reach the end node

        for (auto i = g[f].begin(); i != g[f].end(); i++) {
            if (!vis[*i]) {
                q.push(*i);
                vis[*i] = true;
                parent[*i] = f; // Set parent
            }
        }
    }

    vector<ll> path;
    for (ll i = end; i != -1; i = parent[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end()); // Reverse to get the correct order
    return path;
}

//dfs traversal from start node, in process keeping track of max depth & keeping track of each node's depth & printing order of traversal
ll maxDepth = 0;
void dddfs(ll startNode, ll startDepth){
    vis[startNode] = true;
    depth[startNode]=startDepth;
    maxDepth=max(maxDepth, startDepth);
    cerr << startNode << " ";
    for(auto adjNode : g[startNode]){
        if(!vis[adjNode]) dddfs(adjNode, startDepth+1);
    }
}

//weighted undirected graph 全探索 to find max Hamiltonian path cost
//https://atcoder.jp/contests/abc317/submissions/51739795
ll ans;
void ddddfs(ll v, vector<bool> vis, ll cost){
    ans = max(ans,cost);
    for(auto x:wg[v]){
        if(!vis[x.first]){
            vis[x.first]=true;
            ddddfs(x.first, vis, cost+x.second);
            vis[x.first]=false;
        }
    }
}

map<ll,ll>subtreeSizes; //Map to store subtree sizes for each child of the start node
ll dfsSubtreesHelper(ll startNode){
    vis[startNode] = true;
    ll subtreeSize = 1;
    //cerr << startNode << " ";
    for(auto adjNode : g[startNode]){
        if(!vis[adjNode]){
            subtreeSize+=dfsSubtreesHelper(adjNode);
        }
    }
    return subtreeSize;
}
//main function to call to populate subtreeSizes
ll minSubtreeSize = 3*pow(10,5)+1; //Adjust this to the max given boundary of the problem
void dfsSubtrees(ll startNode){
    vis[startNode] = true;
    for(auto adjNode : g[startNode]){
        subtreeSizes[adjNode]=dfsSubtreesHelper(adjNode); //+1 if want to include startNode in size of subtrees
        minSubtreeSize=min(minSubtreeSize,subtreeSizes[adjNode]);
    }
}

// lowest common ancestor (LCA) class for undirected weighted tree
struct UndirectedWeightedTree {
    using T = long long; // Arbitrary data structure (operator+, operator- must be defined)
    int INVALID = -1;
    int V, lgV;
    int E;
    int root;
    std::vector<std::vector<std::pair<int, int>>> adj; // (nxt_vertex, edge_id)
    // vector<pint> edge; // edges[edge_id] = (vertex_id, vertex_id)
    std::vector<T> weight;     // w[edge_id]
    std::vector<int> par;      // parent_vertex_id[vertex_id]
    std::vector<int> depth;    // depth_from_root[vertex_id]
    std::vector<T> acc_weight; // w_sum_from_root[vertex_id]

    void _fix_root_dfs(int now, int prv, int prv_edge_id) {
        par[now] = prv;
        if (prv_edge_id != INVALID) acc_weight[now] = acc_weight[prv] + weight[prv_edge_id];
        for (auto nxt : adj[now])
            if (nxt.first != prv) {
                depth[nxt.first] = depth[now] + 1;
                _fix_root_dfs(nxt.first, now, nxt.second);
            }
    }

    UndirectedWeightedTree() = default;
    UndirectedWeightedTree(int N) : V(N), E(0), adj(N) {
        lgV = 1;
        while (1 << lgV < V) lgV++;
    }

    void add_edge(int u, int v, T w) {
        adj[u].emplace_back(v, E);
        adj[v].emplace_back(u, E);
        // edge.emplace_back(u, v);
        weight.emplace_back(w);
        E++;
    }

    //Have to set which node you want to consider as root. This function will then run dfs to calculate depth for every node
    void fix_root(int r) {
        root = r;
        par.resize(V);
        depth.resize(V);
        depth[r] = 0;
        acc_weight.resize(V);
        acc_weight[r] = 0;
        _fix_root_dfs(root, INVALID, INVALID);
    }

    //this does binary lifting precalculation -> gives powers of 2 ancestors of every node
    //as every number can be represented in binary, you can find any kth ancestor of any node in logarithmic time if you precalculate above
    std::vector<std::vector<int>> doubling;
    void doubling_precalc() {
        doubling.assign(lgV, std::vector<int>(V));
        doubling[0] = par;
        for (int d = 0; d < lgV - 1; d++)
            for (int i = 0; i < V; i++) {
                if (doubling[d][i] == INVALID)
                    doubling[d + 1][i] = INVALID;
                else
                    doubling[d + 1][i] = doubling[d][doubling[d][i]];
            }
    }

    int kth_parent(int x, int k) {
        if (depth[x] < k) return INVALID;
        for (int d = 0; d < lgV; d++) {
            if (x == INVALID) return INVALID;
            if (k & (1 << d)) x = doubling[d][x];
        }
        return x;
    }

    //returns the lca of 2 nodes
    int lowest_common_ancestor(int u, int v) {
        if (depth[u] > depth[v]) std::swap(u, v);

        v = kth_parent(v, depth[v] - depth[u]);
        if (u == v) return u;
        for (int d = lgV - 1; d >= 0; d--) {
            if (doubling[d][u] != doubling[d][v]) u = doubling[d][u], v = doubling[d][v];
        }
        return par[u];
    }

    //uses LCA to calculate distance between 2 nodes in O(log N) time
    T path_length(int u, int v) {
        // Not distance, but the sum of weights
        int r = lowest_common_ancestor(u, v);
        return (acc_weight[u] - acc_weight[r]) + (acc_weight[v] - acc_weight[r]);
    }
};

//vector for Floyd Warshall which gives you min distance from each node to every other node n.b. can make it vvpll with (path length,-weights) to minimize path whilst maximizing weights in case of ties
//https://atcoder.jp/contests/abc286/submissions/56220080
vector<vector<ll> >ddist;

//n^3 time complexity
void floydWarshall(ll n) {
    // Step 1: Initialization
    ddist.assign(n, vector<ll>(n, INF));

    //Distance to self is always 0
    for (int i = 0; i < n; i++) {
        ddist[i][i] = 0;
    }

    // Step 2: Populate the adjacency matrix
    for (int u = 0; u < n; u++) {
        for (int i = 0; i < g[u].size(); i++) {
            ll v = g[u][i];
            ddist[u][v] = 1; // Assuming unweighted graph, set weight to 1
            // For a weighted graph, you'd set this to the weight of the edge u->v
        }
    }

    // Step 3: Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ddist[i][k] < INF &&ddist[k][j] < INF) {
                    ddist[i][j] = min(ddist[i][j],ddist[i][k] +ddist[k][j]);
                }
            }
        }
    }
}
