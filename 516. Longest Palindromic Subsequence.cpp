The DP state longest[i][j] means for substring between [i, j] inclusive the longest palindromic subsequence.

Basic cases:
if i == j, then longest[i][j] = 1, naturally
if i+1 == j, then longest[i][j] = 2 if s[i] == s[j]
longest[i][j] = 1 otherwise
Transition rule:

s[i] == s[j]
dp[i][j] = max(dp[i+1][j], dp[i][j-1], dp[i+1][j-1] + 2)
s[i] != s[j]
dp[i][j] = max(dp[i+1][j], dp[i][j-1], dp[i+1][j-1])
The condition that only subsequence made it quite simply because at any range [i, j], the s[i], s[j] can be omitted to make the rest range [i+1, j] or [i, j-1] our valid longest palindromic subsequence.

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n));
        
        for(int i=0;i<n;i++) dp[1][i]=1;
        
        for(int i=2;i<=n;i++) //length
            for(int j=0;j<n-i+1;j++) {//start index 
                dp[i][j] = (s[j]==s[i+j-1]?2+dp[i-2][j+1]:max(dp[i-1][j],dp[i-1][j+1]));
            }
        
        return dp[n][0];
    }
};