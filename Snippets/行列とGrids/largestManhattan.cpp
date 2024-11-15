
// Find the largest Manhattan distance between any 2 points (x,y) on a Cartesian plane in O(N)
// https://atcoder.jp/contests/abc178/submissions/59772110
int main(){
    ll N;
    cin >> N;
    vll x(N);
    vll y(N);
    vll xp(N);
    vll yp(N);
    foi(0,N){
        cin >> x[i] >> y[i];
        xp[i]=x[i]-y[i];
        yp[i]=x[i]+y[i];
    }
    sort(all(xp));
    sort(all(yp));
    cout << max(xp[xp.size()-1]-xp[0],yp[yp.size()-1]-yp[0]) << endl;
    return 0;
}