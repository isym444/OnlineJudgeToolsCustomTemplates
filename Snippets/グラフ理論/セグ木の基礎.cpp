

// Custom segment tree explained:
// from: https://codeforces.com/contest/2185/problem/F

void solve()
{
    int N, Q;
    cin >> N >> Q;

    int P = 1 << N;            // number of cows
    vector<int> seg(2 * P, 0); // classic segtree array [1..2P-1]

    // read leaves
    for (int i = 0; i < P; i++)
    {
        cin >> seg[P + i];
    }

    // build internal nodes: XOR
    for (int i = P - 1; i >= 1; i--)
    {
        seg[i] = seg[2 * i] ^ seg[2 * i + 1];
    }

    while (Q--)
    {
        int b, c;
        cin >> b >> c;
        --b; // 0-index cow position

        int node = P + b; // leaf index in segtree
        int curXor = c;   // updated skill of our cow
        ll ans = 0;
        ll blockSize = 1; // subtree size at this level

        // climb from leaf to root
        while (node > 1)
        {
            int sibling = node ^ 1; // toggles last bit: sibling index
            /*
            Why does node ^ 1 swap them?
                XOR with 1 flips the last bit of the number:
                if last bit is 0 (even), it becomes 1 (odd)
                if last bit is 1 (odd), it becomes 0 (even)
                That means:
                even ^ 1 = odd right next to it
                odd ^ 1 = even right next to it
            */
            int siblingXor = seg[sibling];

            bool nodeIsLeft = (node % 2 == 0);

            // Determine if OUR current stack loses against sibling
            bool lose;
            if (nodeIsLeft)
            {
                // left loses only if strictly smaller (tie goes to left)
                lose = (curXor < siblingXor);
            }
            else
            {
                // right loses if <= (tie goes to left)
                lose = (curXor <= siblingXor);
            }

            if (lose)
            {
                ans += blockSize; // all cows in sibling stack are above us
            }

            // merge upward: parent stack XOR
            curXor ^= siblingXor;

            node >>= 1;
            blockSize <<= 1;
        }

        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();
}

/* -----------------top down recursive approach-------------------- */
// If segment fits completely then stop recursion else keep recursing down L&R

vector<pair<ll, ll>> aans;
ll L, R;

void recur(ll l, ll r)
{
    // if current top-down segment being considered fits within L->R range exactly then return
    if (L <= l && r <= R)
    {
        aans.pb(mp(l, r));
        return;
    }
    // split l->r into 2 halves left and right
    ll m = midpoint(l, r);
    // if desired range overlaps with l->m, recur
    if (L < m)
        recur(l, m);
    // if desired range overlaps with m->r, recur
    if (R > m)
        recur(m, r);
}

int main()
{
    cin >> L >> R;
    ll l = 0;
    ll r = 1ll << 60;
    recur(l, r);
    cerr << "Reached" << endl;
    cout << aans.size() << endl;
    fx(aans)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}

/* -----------------bottom up iterative approach-------------------- */
// If there is a segment in layer above that starts/ends on L/R keep moving up rather than add to answer

int main()
{
    ll L, R;
    cin >> L >> R;
    vector<pair<ll, ll>> ans;

    int i = 0;
    while (L < R)
    {
        dbg(make_tuple(L, R));
        // Checking if odd or not is equivalent to checking whether there are larger segments above
        // that start/end on L/R respectively...if there are, want to keep moving up before adding segment to answer
        if (L & 1)
            ans.emplace_back(L << i, (L + 1) << i), L++;
        if (R & 1)
            ans.emplace_back((R - 1) << i, R << i), R--;
        dbg(ans);
        // dbg(L);
        // divide L&R by 2 because i is being increased i.e. moving one step up in segment tree
        // so L&R are the index of the segment at a particular segment tree level (but R is index+1 because of problem statement)
        L >>= 1;
        R >>= 1;
        i++;
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto [l, r] : ans)
        cout << l << ' ' << r << '\n';
    //   dbg(3>>1);
    return 0;
}