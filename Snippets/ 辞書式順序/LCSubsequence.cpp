const ll LCSN = 1000 + 20;
//dp holds the longest common subsequence (LCS) for the 2 substrings to index i & j
//e.g. for s = "hleloworld", t = "thequickbrown"
//i=3 j=4 i.e. dp[3][4]=2 as s[0toi]="hle" & t[0toj]="theq" -> LCS is "he"
ll dp[LCSN][LCSN];
//outputs the value of the longest common subsequence between 2 strings s & t
ll lcs(string s, string t){
    for(ll i = 0; i <= s.size(); i++){
        for(ll j = 0; j <= t.size(); j++){
            //if either s or t is empty then LCS = 0
            if(!i || !j) dp[i][j] = 0;
            //else if cur letters being compared i.e. s[i] or t[i] are the same
            //then dp[i][j] is 1 more than dp[i-1][j-1]
            else if (s[i-1] == t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            //else if cur letters being compared i.e. s[i] or t[i] are not the same
            //then dp[i][j] is max of dp[i-1][j] (comparing cur longest t to s-1)
            //and dp[i][j-1] (comparing cur longest s to t-1)
            else if (s[i-1] != t[j-1]) dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[s.size()][t.size()];
}

