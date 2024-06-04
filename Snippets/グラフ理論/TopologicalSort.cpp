vll ans;
vvll P;
vll visited;

void dfs(ll node){
    visited[node]=1;
    for(auto neighbour:P[node]){
        if(visited[neighbour]) continue;
        dfs(neighbour);
    }
    ans.pb(node);
}
