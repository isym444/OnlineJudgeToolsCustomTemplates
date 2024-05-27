ll mod=1e9+7;
//ll mod=1000;
//modular exponentiation: calculates a^b mod c where a^b is a crazy big number and would usually overflow. Change mod above as needed
ll mpow(ll base, ll exp)
{
    base %= mod;
    ll result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}
