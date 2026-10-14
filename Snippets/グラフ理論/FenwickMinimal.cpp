struct Fenwick
{
    int n;
    vector<long long> t;
    Fenwick(int n) : n(n), t(n + 1) {}
    void add(int i, long long v)
    {
        for (++i; i <= n; i += i & -i)
            t[i] += v;
    } // 0-indexed
    long long sum(int r)
    {
        long long s = 0;
        for (; r > 0; r -= r & -r)
            s += t[r];
        return s;
    } // prefix [0, r)
    long long sum(int l, int r) { return sum(r) - sum(l); } // range [l, r)
};
Fenwick fw(n);
fw.add(3, 5); // a[3] += 5
fw.sum(1, 4); // a[1] + ... + a[3]