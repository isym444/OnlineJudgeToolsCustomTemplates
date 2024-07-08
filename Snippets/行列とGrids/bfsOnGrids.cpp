
//https://atcoder.jp/contests/abc317/submissions/55385388
queue<tuple<ll,ll>> q;

q.push(mp(Spos.first,Spos.second));

vector<vector<ll>> visited(H, vector<ll>(W,0));
visited[Spos.first][Spos.second]=1;

//make sure not to pass visited[i][j] into values of queue i.e. as part of a tuple as will cause TLE. Instead updated external visited directly
while(!q.empty()){
    pair<ll,ll> cur = q.front();
    auto [i,j] = cur;
    q.pop();
    fok(0,4){
            ll di = i+dy_wasd[k];
            ll dj = j+dx_wasd[k];
            if(isvalidsingle(di,0,H-1)&&isvalidsingle(dj,0,W-1)){
                if(visited[di][dj]) continue;
                if(G[di][dj]!='.'&&G[di][dj]!='S'&&G[di][dj]!='G') continue;
                visited[di][dj]=visited[i][j]+1;
                q.push(mp(di,dj));
            }
        }
}