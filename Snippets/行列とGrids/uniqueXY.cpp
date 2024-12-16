
auto uniquexy = [&](ll x, ll y)->ll{
    return(x*W+y);
};
auto getOriginalXY = [&](ll uniquexy) -> pair<ll, ll> {
  return {uniquexy / W, uniquexy % W};
};

ll uniquexy(ll x, ll y){
    return x*W+y;
}
