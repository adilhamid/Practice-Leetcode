// Notes for the coding
/*
Initially i will check if the lenght of the given array is less than 2, then return NULL

Else i want to store the previous values in the unordered_map so that when i check for that value, 
i will be able to check in O(1)

If the number doesn't exist i will move to next number and add the number to my map.


*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        int len = nums.size();
        if(!len || len<2) return {};
        
        unordered_map<int, int> mymap;
        int findVal =0;
        vector<int> result;
        
        for(int i =0; i<len; i++){
            
            findVal = target - nums[i];
            
            if(mymap.find(findVal) != mymap.end()){
                result.push_back(mymap[findVal]);
                result.push_back(i);
                return result;
            }
           mymap[nums[i]] = i;
        }
        
        return {};
    }
};