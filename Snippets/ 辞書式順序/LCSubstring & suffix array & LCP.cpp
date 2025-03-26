

// longest repeated substring within a single string
cin >> S;
auto sa = suffix_array(S);
auto lcp = lcp_array(S,sa);
// largest value in lcp is the length of the longest repeated substring


// Count of distinct substrings in a single string:

cin >> S;
auto sa = suffix_array(S);
dbg(sa);
auto lcp = lcp_array(S, sa);
dbg(lcp);
ll n = S.length();
ll ans = n*(n+1)/2;
dbg(ans);
ll sum=0;
fx(lcp){
    sum+=x;
}
ans-=sum;
cout << ans << endl;



string longestCommonSubstring(const string &s1, const string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // DP table

    int maxLength = 0; // Stores max length of common substring
    int endIndex = 0;  // Stores end index of LCS in s1

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1; // Store end index of LCS in s1
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return s1.substr(endIndex - maxLength + 1, maxLength);
}

