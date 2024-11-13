//https://atcoder.jp/contests/abc361/editorial/10353
//use this to check x, y and z lines intersect as per needed i.e. if 2d or 3d problem
//intersect as in overlap in a 1d line
auto intersect = [&](ll l1, ll r1, ll l2, ll r2){
        return max(l1, l2) < min(r1,r2);
    };

//to check if 2 cuboids (ABC DEF are the 2 points on diagonal of cuboid uniquely defining it) (GHI JKL) have +ve volume i.e. intersect
//ad is x coordinate line, be is y coordinate line, cf is z coordinate line between points ABC & DEF
if(intersect(a,d,g,j)&&intersect(b,e,h,k)&&intersect(c,f,i,l)) return true;
    return false;



