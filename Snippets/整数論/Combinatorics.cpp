
// When don't have a prime mod, must use pascals triangle method
//  Build nCk with Pascal (no modular inverses; works for composite mod)
//  maxN should be at least the largest n you'll query
struct Binom
{
    int maxN;
    long long modulus;
    std::vector<std::vector<long long>> C; // C[n][k] = nCk % modulus

    Binom(int maxN_, long long modulus_)
        : maxN(maxN_), modulus(modulus_),
          C(maxN_ + 1, std::vector<long long>(maxN_ + 1, 0))
    {

        C[0][0] = 1 % modulus;
        for (int n = 0; n < maxN; ++n)
        {
            for (int k = 0; k <= n; ++k)
            {
                long long v = C[n][k];
                if (!v)
                    continue;
                C[n + 1][k] = (C[n + 1][k] + v) % modulus;
                C[n + 1][k + 1] = (C[n + 1][k + 1] + v) % modulus;
            }
        }
    }

    long long operator()(int n, int k) const
    {
        if (k < 0 || k > n || n > maxN)
            return 0;
        return C[n][k];
    }
};
// USAGE:
long long MOD = /* your modulus */;
int maxN = 5000; // e.g. sum of C_i
Binom nCk(maxN, MOD);

long long x = nCk(10, 3); // 10C3 % MOD

// ===============================

// nCx with MINT (USE OVER struct combination BELOW!)
mint choose(int n, int a)
{
    mint x = 1, y = 1;
    rep(i, a)
    {
        x *= n - i;
        y *= i + 1;
    }
    return x / y;
}

// number of ways to select x boxes from n boxes without regard to the order of selection
// number of ways to choose a elements out of n distinct elements without regard to order.
// Counts the number of subsets of size a from a set of n distinct elements.
// Applicable when selecting items without replacement and where the order doesn't matter.
mint choose(int n, int a)
{
    mint x = 1, y = 1;
    rep(i, a)
    {
        x *= n - i;
        y *= i + 1;
    }
    return x / y;
}

// ncx where can have 0 in a box
mint f2(ll items, ll boxes)
{
    return (choose(items + boxes - 1, boxes - 1));
}

// ncx where must have 1 at least in every box
mint f(ll items, ll boxes)
{
    // if(a<b) return 0;
    if (boxes == 0)
        return 0; // cannot place items if there are no boxes!
    return f2(items - boxes, boxes);
}

int main()
{
    ll N, K;
    cin >> N >> K;
    ll blue = K;
    ll red = N - K;

    foi(1, K + 1)
    {
        mint S = 0;
        S += f(red, i - 1);
        S += f(red, i);
        S += f(red, i);
        S += f(red, i + 1);
        mint ans = f(blue, i) * S;
        cout << ans << endl;
    }
    return 0;
}

// nCx with MINT (use with minimal mint)
// how to use:
//  combination cc = combination(n);
//  mint chooseA = cc(n,a);
struct combination
{
    vector<mint> fact, ifact;
    combination(int n) : fact(n + 1), ifact(n + 1)
    {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i)
            ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(int n, int k)
    {
        if (k < 0 || k > n)
            return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
};

// use if possible as faster than nCx
long long nC2(int n)
{
    return static_cast<long long>(n) * (n - 1) / 2;
}

// order matters so larger than nCx
long long nPx(int n, int x)
{
    if (x > n)
        return 0;

    long long result = 1;
    for (int i = n; i > n - x; --i)
    {
        result *= i;
    }
    return result;
}

// order doesn't matter so smaller than nPx
// O(N each time you call)
long long nCx(int n, int x)
{
    if (x > n)
        return 0;
    if (x * 2 > n)
        x = n - x; // Take advantage of symmetry, nCx == nC(n-x)
    if (x == 0)
        return 1;

    long long result = 1;
    for (int i = 1; i <= x; ++i)
    {
        result *= n - (x - i);
        result /= i;
    }
    return result;
}

// nCx but by precomputation of values using Pascal's triangle. Precomputation is O(N^2) but reading out is O(1)

// Define a constant for the maximum size we want to precompute
const int MAX_N = 60;
long long c[MAX_N + 1][MAX_N + 1];
bool isInitialized = false; // Flag to check if coefficients are initialized

// Function to initialize Pascal's triangle
void initializeBinomialCoefficients()
{
    if (isInitialized)
        return; // Skip if already initialized

    // Set the base case
    c[0][0] = 1;

    // Fill the triangle using the recurrence relation
    for (int i = 1; i <= MAX_N; ++i)
    {
        c[i][0] = 1; // nC0 is always 1
        for (int j = 1; j <= i; ++j)
        {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    isInitialized = true; // Mark as initialized
}

// Function to retrieve binomial coefficient nCx
long long nCx(int n, int x)
{
    // Initialize binomial coefficients if not already done
    if (!isInitialized)
        initializeBinomialCoefficients();

    // Check bounds and return the coefficient
    if (x > n || n > MAX_N || x < 0)
        return 0;
    return c[n][x];
}