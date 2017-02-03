class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
    const int m = dungeon.size();
    const int n = dungeon[0].size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n - 1] = 1; 
    for(int i = m - 1; i >= 0; --i)
        for(int j = n - 1; j >= 0; --j)
            {
            dp[j] =  min(dp[j], dp[j + 1]) - dungeon[i][j] <= 0 ? 1 :  min(dp[j], dp[j + 1]) - dungeon[i][j];
            }
    return dp[0];
}

};