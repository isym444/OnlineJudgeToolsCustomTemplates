//use this to check if a graph is bipartite i.e. can be coloured with all adjacent vertices with alternating colours
ll N,M;
cin >> N >> M;
dsu dd(2*N);
foi(0,M){
    ll u,v;
    cin >> u >> v;
    u--;
    v--;
    dd.merge(u,v+N);
    dd.merge(v,u+N);
}
dbg(dd.groups());
foi(0,N){
    if(dd.same(i,i+N)){
        //output 0 if not bipartite
        cout << 0 << endl;
        return 0;
    }
}

//add code below to check how many edges can be added while still keeping bipartite property
ll ans = 0;
ll nodesSoFar = 0;
vll done(N,0);
fx(dd.groups()){
    if(done[x[0]%N]) continue;
    dbg(x);
    ll c1=0;
    ll c2=0;
    for(auto y:x){
        if(y<N){
            c1++;
        }else{
            c2++;
        }
        done[y%N]=1;
    }
    ans+=c1*c2;
    dbg(mp(c1,c2));
    ans+=nodesSoFar*x.size();
    nodesSoFar+=x.size();
}
//ans gives total possible edges that graph could theoretically have while still staying bipartite
//subtract M, which is number of initial edges in graph as you are checking the number of edges that can be ADDED while still keeping bipartite property
cout << ans-M << endl;
return 0;