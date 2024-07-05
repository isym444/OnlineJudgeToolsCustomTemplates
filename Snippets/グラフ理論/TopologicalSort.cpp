deque<ll> ans;
vvll to;
vll visited;

void dfs(ll node){
    visited[node]=1;
    for(auto neighbour:to[node]){
        if(visited[neighbour]) continue;
        dfs(neighbour);
    }
    ans.push_front(node);
}

//ensures runs dfs for all nodes in case graph not connected
foi(0,N){
    dfs(dfs, i);
}



// ---------------------------------------------


// Topological sort in lexicographically smallest order (USING KAHN'S ALGORITHM)
vector<vector<int>> to(n); // Adjacency list for the graph
vector<int> indeg(n); // In-degree of each node

rep(i,m) {
    int a, b;
    cin >> a >> b;
    --a; --b; // Convert to 0-based indexing
    to[a].push_back(b); // Directed edge a -> b
    indeg[b]++; // Increase in-degree of b
}

// Priority queue to get the smallest element first
priority_queue<int, vector<int>, greater<int>> q;
rep(i,n) if (indeg[i] == 0) q.push(i); // Add nodes with zero in-degree

vector<int> ans; // Store the result permutation
while (!q.empty()) {
    int v = q.top(); q.pop();
    ans.push_back(v); // Add the smallest available node
    for (int u : to[v]) {
        indeg[u]--; // Decrease in-degree of neighbors
        if (indeg[u] == 0) q.push(u); // Add to queue if in-degree is zero
    }
}

if (ans.size() != n) cout << -1 << endl; //h Check if Graph has a cycle
else {
    for (int v : ans) cout << v + 1 << " "; // Convert back to 1-based indexing
    cout << endl;
}


//-------------------------------------------------------

//h check there is only one valid topological order
foi(0,N-1) {
    int a = ans[i], b = ans[i+1];
    bool ok = false;
    for (int v : to[a]) if (v == b) ok = true;
    if (!ok) { 
        cout << "No" << endl; 
        return 0; 
    }
}