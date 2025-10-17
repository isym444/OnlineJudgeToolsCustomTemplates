// when dif between each term is 1
auto arithmeticSum = [&](ll L, ll R) -> ll
{
    return (L + R) * (R - L + 1) / 2;
};

// when dif between each term is d
auto arithmeticSum = [&](ll L, ll R, ll d) -> ll
{
    if (L > R)
        return 0LL;
    ll n = (R - L) / d + 1;
    return n * (L + R) / 2;
};
