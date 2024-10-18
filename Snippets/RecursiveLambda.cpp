auto dfs = [&](auto dfs, ll v) -> void {
    if(ans==1e6) return;
    visited[v]=1;
    ans++;
    for(auto x:adj[v]){
        if(!visited[x]){
            dfs(dfs, x);
            // ans++;
        }
    }
    visited[v]=0;
};

dfs(dfs,(ll)0);



auto find = [&](auto&& self, int x) -> int {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = self(self, parent[x]);
    }
};





