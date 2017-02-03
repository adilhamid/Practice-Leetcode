class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int len = nums.size();
        
        int sum =0;
        int patches = 0;
        int i =0; 
        while(sum<n){
            
            if(i < len && nums[i] <= sum+1){
                sum += nums[i];
                i++;
            }
            else{
                patches++;
                if (sum > (INT_MAX - 1) / 2) {
                    sum = INT_MAX;
                     }
                else {
                sum = sum * 2 + 1;
                 }
            }
            
        }
        return patches;
        
    }
};