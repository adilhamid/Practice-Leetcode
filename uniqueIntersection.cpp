class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(!len1 || !len2) return {};
        
        unordered_map<int, bool> myHast;
        
        for(int i =0; i< len1; i++){
            myHast[nums1[i]] = true;
        }
        
        vector<int> result;
        
        for(int i =0; i< len2; i++){
            
           if(myHast[nums2[i]]){
               result.push_back(nums2[i]);
               myHast[nums2[i]] = false;
           }
            
        }
       
        return result;
    }
};