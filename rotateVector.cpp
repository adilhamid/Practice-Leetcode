class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(!k) return;
        
        int len = nums.size();
        
        k = k % len;
        
       if(!k) return;
        
        reverse(nums.begin(), nums.begin()+len-k);
        reverse(nums.begin()+len-k, nums.end());
        reverse(nums.begin(), nums.end());
        
        return ;

        for(int i = 0; i<len-k; i++){
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }

        return;
    }
};