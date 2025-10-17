
// get(int l, int r) -> unsigned
// Returns the hash of substring s[l..r) in O(1).

template <unsigned mod>
struct RollingHash
{
  vector<unsigned> hashed, power;

  inline unsigned mul(unsigned a, unsigned b) const
  {
    return (unsigned)((1ULL * a * b) % mod);
  }

  RollingHash(const string &s, unsigned base = 10007)
  {
    int sz = (int)s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for (int i = 0; i < sz; i++)
    {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + s[i];
      if (hashed[i + 1] >= mod)
        hashed[i + 1] -= mod;
    }
  }

  unsigned get(int l, int r) const
  {
    unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
    if (ret >= mod)
      ret -= mod;
    return ret;
  }

  unsigned connect(unsigned h1, int h2, int h2len) const
  {
    unsigned ret = mul(h1, power[h2len]) + h2;
    if (ret >= mod)
      ret -= mod;
    return ret;
  }

  int LCP(const RollingHash<mod> &b, int l1, int r1, int l2, int r2)
  {
    int len = min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while (high - low > 1)
    {
      int mid = (low + high) / 2;
      if (get(l1, l1 + mid) == b.get(l2, l2 + mid))
        low = mid;
      else
        high = mid;
    }
    return low;
  }
};

using RH = RollingHash<1000000007>;

// if combining into 2D rolling hash, will need the following arithmetic functions for the vertical hash calculations
const int B2 = 911382323;
static constexpr unsigned MOD = 1000000007u;
// ===============
auto addm = [&](unsigned a, unsigned b)
{ a += b; if (a >= MOD) a -= MOD; return a; };
auto subm = [&](unsigned a, unsigned b)
{ return (a >= b) ? (a - b) : (a + MOD - b); };
RH dummy(""); // just to use dummy.mul()

// --- powers for vertical hash (length sr) ---
vector<unsigned> powB2(sr + 1, 1);
for (int i = 1; i <= sr; ++i)
  powB2[i] = dummy.mul(powB2[i - 1], B2);
// ===============

// how to use in main
main()
{
  int n = in();
  string s;
  cin >> s;
  RH rh(s);
  int l = 0, r = n;
  while (l < r - 1)
  {
    int mid = (l + r) / 2;
    map<ll, int> m;
    bool flag = false;
    rep(i, n + 1 - mid)
    {
      ll now = rh.get((int)i, (int)i + mid);
      int t = m[now];
      if (t == 0)
        m[now] = i + 1;
      else
      {
        if (i >= m[now] - 1 + mid)
          flag = true;
      }
    }
    if (flag)
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;

  RH rhS(s); // hash for first string
  RH rhT(t); // hash for second string

  int q; // number of queries
  cin >> q;

  // Each query: l1 r1 l2 r2 (0-indexed, r is exclusive)
  // LCP is computed between s[l1..r1) and t[l2..r2)
  while (q--)
  {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int lcpLen = rhS.LCP(rhT, l1, r1, l2, r2);
    cout << lcpLen << "\n";
  }

  // --- Examples (no input) ---
  // Longest common prefix of suffixes s[i..] and t[j..]:
  // int i = 2, j = 3;
  // int lcpSuffix = rhS.LCP(rhT, i, (int)s.size(), j, (int)t.size());

  // LCP within the SAME string s between suffixes starting at i and j:
  // int i = 1, j = 4;
  // int lcpSame = rhS.LCP(rhS, i, (int)s.size(), j, (int)s.size());

  return 0;
}