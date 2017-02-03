class Solution {
public:
    int rob(vector<int>& nums) {
        
        int numsSize = nums.size();
        
        if(numsSize < 2) return numsSize ? nums[0] : 0;
        
        return max(robberChamp(nums, 0, numsSize-2) , robberChamp(nums,1,numsSize-1));
        
    }
    
    int robberChamp(vector<int> nums, int start, int end){
        int pre=0, curr =0;
        for(int i =start; i<=end; i++ ){
            int temp = max(pre+nums[i], curr);
            pre = curr;
            curr = temp;
        }
        return max(pre, curr);
    }
};