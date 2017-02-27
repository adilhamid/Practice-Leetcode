class Solution {
public:
    // Dp Based Solution
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        
        vector<bool> dp(len+1, false);
        
        dp[0] = true;
        
        for(int i =1; i<=len; i++){
            
            for(int j =i-1; j>=0; j--){
                
                if(dp[j]){
                    if(find(wordDict.begin(), wordDict.end(), s.substr(j,i-j)) != wordDict.end()){
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[len];
    }
};