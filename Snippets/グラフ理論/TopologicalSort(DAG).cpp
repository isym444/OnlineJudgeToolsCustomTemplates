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
// This ensures we get the lexicographically smallest topological order
// If we use a queue instead, we get A topological order, not necessarily the smallest
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

// If ans doesn't have all the nodes, this means at some point in the while loop
// we didn't have any nodes with in-degree zero, i.e. there is a cycle
// so while loop exited before all nodes were able to be added to ans
if (ans.size() != n) cout << -1 << endl; //h Check if Graph has a cycle
else {
    for (int v : ans) cout << v + 1 << " "; // Convert back to 1-based indexing
    cout << endl;
}


//-------------------------------------------------------

//h check there is only one valid topological order
// if the topological order = chain of nodes in the graph then topological order is unique
// otherwise there are multiple topological orders
// e.g. if you have:
/* a
  / \
 v   v
 b   e
  \ /
   v
   d
 */
// then topological order could be a, b, e, d or a, e, b, d
// so there are multiple topological orders
// this is determined because b&e are adjacent in topological order but there is no direct edge between b&e
foi(0,N-1) {
    int a = ans[i], b = ans[i+1];
    bool ok = false;
    for (int v : to[a]) if (v == b) ok = true;
    if (!ok) { 
        cout << "No" << endl; 
        return 0; 
    }
}