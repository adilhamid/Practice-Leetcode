class Solution {
public:

    void getSubsets(vector<int>nums, int start, vector<int>& sub, vector<vector<int>>& subs){
        subs.push_back(sub);
        for(int i = start; i<nums.size(); i++){
            sub.push_back(nums[i]);
            getSubsets(nums,i+1, sub, subs);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsI(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> subs;
        vector<int> sub;
        
        getSubsets(nums, 0,sub, subs);
        
        return subs;
    }
    
     vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int n = subs.size();
            for (int j = 0; j < n; j++) {
                subs.push_back(subs[j]); 
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
    
};