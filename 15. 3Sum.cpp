class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty()) return {};
        
        sort(nums.begin(), nums.end());
        
        int start=0, iter, right=nums.size()-1;
        int sum;
        vector<vector<int>> result;
        
        while(start < right){
            iter = start+1;
            sum = nums[start];
            right = nums.size()-1;
            
            while(iter<right){
                int tempSum = nums[iter] + nums[right];
                
                if(sum + tempSum == 0 ){
                    vector<int> temp;
                    
                    temp.push_back(nums[start]);
                    temp.push_back(nums[iter]);
                    temp.push_back(nums[right]);
                    result.push_back(temp);

                    while(iter+1 < right && nums[iter] == nums[iter+1]){
                        iter++;
                    }
                    
                    while(right-1 > iter && nums[right] == nums[right-1]){
                        right--;
                    }
                    iter++;
                    right--;
                }
                else if(sum + tempSum > 0 ){
                    right--;
                }
                else if(sum + tempSum < 0){
                    iter++;
                }
                
            }
            while(start+1 <right && nums[start] == nums[start+1]) start++;
            start++;
        }
        
        return result;
        
    }
};