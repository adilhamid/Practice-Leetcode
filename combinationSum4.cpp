class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        int len = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(target+1);
        dp[0] =1;
        
        for(int i =1; i<=target; i++){
            for(int num:nums){
                if(i<num) break;
                dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};