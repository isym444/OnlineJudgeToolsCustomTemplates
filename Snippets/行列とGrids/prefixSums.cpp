
// Function to build the prefix sum grid
vector<vector<ll>> build2DPrefixSumGrid(const vector<vector<ll>>& grid) {
    ll n = grid.size();
    ll m = grid[0].size();
    vector<vector<ll>> prefix(n, vector<ll>(m, 0));

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            prefix[i][j] = grid[i][j];
            if (i > 0) prefix[i][j] += prefix[i-1][j];
            if (j > 0) prefix[i][j] += prefix[i][j-1];
            if (i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
        }
    }

    return prefix;
}

// Function to get the sum of the subgrid from (x1, y1) to (x2, y2) -> i.e. top left to bottom right coordinate
ll getSubgridSum2D(const vector<vector<ll>>& prefix, ll x1, ll y1, ll x2, ll y2) {
    // Adjust for 0-indexed array
    // x1--; y1--; x2--; y2--;

    ll sum = prefix[x2][y2];
    if (x1 > 0) sum -= prefix[x1-1][y2];
    if (y1 > 0) sum -= prefix[x2][y1-1];
    if (x1 > 0 && y1 > 0) sum += prefix[x1-1][y1-1];

    return sum;
}


vector<vector<vector<ll>>> build3DPrefixSum(const vector<vector<vector<ll>>>& grid, ll N) {
    vector<vector<vector<ll>>> prefix(N, vector<vector<ll>>(N, vector<ll>(N, 0)));

    for (ll x = 0; x < N; ++x) {
        for (ll y = 0; y < N; ++y) {
            for (ll z = 0; z < N; ++z) {
                prefix[x][y][z] = grid[x][y][z];
                if (x > 0) prefix[x][y][z] += prefix[x-1][y][z];
                if (y > 0) prefix[x][y][z] += prefix[x][y-1][z];
                if (z > 0) prefix[x][y][z] += prefix[x][y][z-1];

                if (x > 0 && y > 0) prefix[x][y][z] -= prefix[x-1][y-1][z];
                if (x > 0 && z > 0) prefix[x][y][z] -= prefix[x-1][y][z-1];
                if (y > 0 && z > 0) prefix[x][y][z] -= prefix[x][y-1][z-1];

                if (x > 0 && y > 0 && z > 0) prefix[x][y][z] += prefix[x-1][y-1][z-1];
            }
        }
    }
    return prefix;
}

//assumes 0 indexed coordinates
ll getSubgridSum3D(const vector<vector<vector<ll>>>& prefix, ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
    ll sum = prefix[x2][y2][z2];

    if (x1 > 0) sum -= prefix[x1-1][y2][z2];
    if (y1 > 0) sum -= prefix[x2][y1-1][z2];
    if (z1 > 0) sum -= prefix[x2][y2][z1-1];

    if (x1 > 0 && y1 > 0) sum += prefix[x1-1][y1-1][z2];
    if (x1 > 0 && z1 > 0) sum += prefix[x1-1][y2][z1-1];
    if (y1 > 0 && z1 > 0) sum += prefix[x2][y1-1][z1-1];

    if (x1 > 0 && y1 > 0 && z1 > 0) sum -= prefix[x1-1][y1-1][z1-1];

    return sum;
}
