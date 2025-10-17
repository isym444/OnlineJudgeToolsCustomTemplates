
// time complexity: O(log(min(a,b))).
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
