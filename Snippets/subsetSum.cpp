//checks whether target sum S can be made with elements of vector A
int subsetSum(vector<int> A, int S){
    vector<int> dp(S+1, 0);
    dp[S] = 1;
    for(int a : A){
        for(int i=0; i+a<=S; i++) dp[i] |= dp[i+a];
    }
    return dp[0];
}