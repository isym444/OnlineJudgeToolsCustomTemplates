

/* -----------------top down recursive approach-------------------- */
// If segment fits completely then stop recursion else keep recursing down L&R

vector<pair<ll,ll>> aans;
ll L,R;

void recur(ll l, ll r){
    //if current top-down segment being considered fits within L->R range exactly then return
    if(L<=l&&r<=R){
        aans.pb(mp(l,r));
        return;
    }
    //split l->r into 2 halves left and right
    ll m = midpoint(l,r);
    //if desired range overlaps with l->m, recur
    if(L<m) recur(l,m);
    //if desired range overlaps with m->r, recur
    if(R>m) recur(m,r);
}

int main(){
    cin >> L >> R;
    ll l=0;
    ll r=1ll<<60;
    recur(l,r);
    cerr << "Reached" << endl;
    cout << aans.size() << endl;
    fx(aans){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}

/* -----------------bottom up iterative approach-------------------- */
// If there is a segment in layer above that starts/ends on L/R keep moving up rather than add to answer

int main() {
    ll L, R;
    cin >> L >> R;
    vector<pair<ll,ll>> ans;

    int i = 0;
    while (L < R) {
        dbg(make_tuple(L,R));
        //Checking if odd or not is equivalent to checking whether there are larger segments above
        //that start/end on L/R respectively...if there are, want to keep moving up before adding segment to answer
        if (L&1) ans.emplace_back(L<<i, (L+1)<<i), L++;
        if (R&1) ans.emplace_back((R-1)<<i, R<<i), R--;
        dbg(ans);
        // dbg(L);
        //divide L&R by 2 because i is being increased i.e. moving one step up in segment tree
        //so L&R are the index of the segment at a particular segment tree level (but R is index+1 because of problem statement)
        L >>= 1; R >>= 1; i++;
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto [l,r] : ans) cout << l << ' ' << r << '\n';
    //   dbg(3>>1);
    return 0;
}