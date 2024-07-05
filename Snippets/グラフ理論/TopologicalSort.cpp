vll ans;
vvll to;
vll visited;

void dfs(ll node){
    visited[node]=1;
    for(auto neighbour:to[node]){
        if(visited[neighbour]) continue;
        dfs(neighbour);
    }
    ans.pb(node);
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