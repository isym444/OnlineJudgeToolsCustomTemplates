// 2 pointers clean approach

int main()
{
    nyan;
    int N, D;
    cin >> N >> D;
    vll A(N);
    cin >> A;
    set<ll> s;
    s.insert(-INF);
    s.insert(INF);
    auto checker = [&](ll RR) -> bool
    {
        auto afterIt = s.lower_bound(A[RR]);
        auto afterVal = *afterIt;
        auto beforeIt = prev(afterIt);
        auto beforeVal = *beforeIt;

        if (A[RR] - beforeVal < D)
        {
            return false;
        }

        if (afterVal - A[RR] < D)
        {
            return false;
        }

        return true;
    };

    ll ans = 0;

    // 2 POINTERS STARTS HERE
    int L = 0;
    for (int R = 0; R < N; R++)
    {
        while (true)
        {
            if (checker(R))
                break;
            s.erase(A[L]);
            L++;
        }
        ans += R - L + 1;
        s.emplace(A[R]);
    }

    cout << ans << endl;

    return 0;
}

// Guaranteed, no thinking binary search:

/*

while(L<=R) (<= rather than <)
keep an ans variable that updates whenever a better answer (if looking for transition point) or the answer (if looking for a single value)

AND make sure L is always a valid value i.e. not -1

*/

// Ternary search with binary search:

int main()
{
    nyan;
    int t;
    cin >> t;
    while (t--)
    {
        int m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;
        int r = m / k; // max number of k type coins that can be used -> calculate number of fancy coins of each type this requires as f(x)
        int l = 0;     // min number of k type coins that can be used

        auto f = [&](int numOfK) -> int
        {
            int total = numOfK * k;
            int fancyK = max(0, numOfK - ak);
            int onesNeeded = m - total;
            int fancyOnes = max(0, onesNeeded - a1);
            return fancyK + fancyOnes;
        };

        while (r - l > 3)
        {
            int mid = midpoint(l, r);
            if (f(mid) < f(mid + 1))
            {
                r = mid + 1;
            }
            else
            {
                l = mid;
            }
        }

        int best = l;
        for (int i = l + 1; i <= r; i++)
        {
            if (f(i) < f(best))
                best = i;
        }
        cout << f(best) << endl;
    }
    return 0;
}