//https://atcoder.jp/contests/abc361/editorial/10353
//check x, y and z lines intersect
auto intersect = [&](ll l1, ll r1, ll l2, ll r2){
        return max(l1, l2) < min(r1,r2);
    };