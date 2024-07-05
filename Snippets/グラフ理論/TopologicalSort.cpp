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

//check there is only one valid topological order
foi(0,N-1) {
    int a = ans[i], b = ans[i+1];
    bool ok = false;
    for (int v : to[a]) if (v == b) ok = true;
    if (!ok) { 
        cout << "No" << endl; 
        return 0; 
    }
}