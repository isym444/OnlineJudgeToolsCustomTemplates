//C / A = B where each is a vector representing coefficients of polynomial including the x^0 coefficient i.e. the c in mx+c
vector<long long> polynomialDivision(const vector<long long>& c, const vector<long long>& a) {
    int n = a.size() - 1;  // Degree of A(x)
    int m = c.size() - n - 1;  // Degree of B(x)
    vector<long long> b(m + 1);
    vector<long long> temp_c = c;  // Copy of c to modify during the process

    for (int i = m; i >= 0; --i) {
        b[i] = temp_c[i + n] / a[n];
        for (int j = 0; j <= n; ++j) {
            temp_c[i + j] -= b[i] * a[j];
        }
    }

    return b;
}

