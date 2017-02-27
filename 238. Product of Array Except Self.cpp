class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        
        int fromLast =1;
        int fromStart =1;
        
        vector<int> result(len,1);
        
        for(int i =0; i< len ; i++){
            result[i] *= fromStart;
            fromStart *= nums[i];
            
            result[len-1-i] *= fromLast;
            fromLast *= nums[len-1-i];
        }
        
        return result;
    }
};