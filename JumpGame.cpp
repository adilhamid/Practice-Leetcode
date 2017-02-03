class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int len = nums.size();
        if(nums[0] >= len-1) return true;
        
        int lastPos = len-1;
        
        for(int i =len-2; i>=0; --i){
            if( (lastPos-i) <= nums[i]){ 
                lastPos = i;
            }
        }
        return lastPos==0;
    }
};