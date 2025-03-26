
// suffix array is the array of starting indices of the sorted suffixes of a string
// e.g. banana suffixes:
/* 
"banana"
"anana"
"nana"
"ana"
"na"
"a"
*/
// when sorted:
/* 
"banana"
"anana"
"nana"
"ana"
"na"
"a"
*/
// so suffix array is: SA = [5, 3, 1, 0, 4, 2]

// An LCP Array tells us the length of the longest common prefix between each pair of consecutive suffixes in the sorted suffix array.
// for banana suffix array: LCP = [0, 1, 3, 0, 0, 2]


//  Given a string 'S' and a string 'T' determine whether the string T is a substring of S, if so return the index at which T is a substring of S.
/* Solution using Suffix Array: We can notice that any substring is a prefix of some suffix. In the suffix array for string 'S' we cut off the first |T| characters of each suffix and get all the substring of length atmost |T| in a sorted order. In order to find S we can simply apply binary search and compare the mid string to string S.

If mid string of suffix array is lexicographically smaller than 'T' then binary search on right half.
If mid string of suffix array is lexicographically greater than 'T' then binary search on left half.
If both the string match return that index as our result. */


// longest repeated substring within a single string (longest common prefix for the suffixes starting at i & j)
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
// total substrings
ll ans = n*(n+1)/2;
dbg(ans);
ll sum=0;
fx(lcp){
    sum+=x;
}
// remove duplicate substrings
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

