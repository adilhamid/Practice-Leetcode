class Solution {
public:
    bool canPartitionFail(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int forwardSum=0, backwardSum =0;
       
        forwardSum = nums[0];
        backwardSum = nums[nums.size()-1];
        
        int i=0, j = nums.size()-1;
        
        while(i<j){
    
            if(backwardSum == forwardSum ){
                if(i == j-1) return true;
                else{
                    forwardSum += nums[++i];
                    backwardSum += nums[--j];
                }
            }
            
            else if (forwardSum > backwardSum && i<j){
                    backwardSum += nums[--j];
            }
                
            else if (forwardSum < backwardSum && j>i){
                forwardSum += nums[++i];
            }
            
            else
             return false; 
        }
        return false;
        
    }
    
     bool canPartitionDP(vector<int>& nums) {
         int sum = accumulate(nums.begin(), nums.end(),0);
         if(sum & 1) return false;
         int target = sum >> 1;
         vector<int> dp(target+1, 0);
         dp[0] = 1;
         for(int num : nums){
             for(int i = target; i>= num ; i--){
                 dp[i] = dp[i] || dp[i-num];
             }
         }
         return dp[target];
     }
       
       bool canPartition(vector<int>& nums) {
           int sum =0;
           bitset<((100*200) / 2) -1> bit(1);
           
           for(int num : nums){
               sum += num;
               bit |= bit << num;
           }
           
           return !(sum & 1) && bit[sum >> 1];
       }
     
};
