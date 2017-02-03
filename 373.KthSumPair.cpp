class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<pair<int,int>> result;
        
        if(!len1 || !len2 || k<=0) return result;
         auto comp = [&nums1, &nums2](pair<int, int> a , pair<int,int> b){
             return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
         
         priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> minHeap(comp);
         minHeap.emplace(0,0);
        
         while(k-- >0 && !minHeap.empty()){
             auto indexPair = minHeap.top(); minHeap.pop();
             result.emplace_back(nums1[indexPair.first], nums2[indexPair.second]);
             if(indexPair.first +1 < len1)
                minHeap.emplace(indexPair.first+1, indexPair.second);
             if(indexPair.first ==0 && indexPair.second+1 < len2)
                minHeap.emplace(indexPair.first, indexPair.second + 1);
         }
         return result;
    }
};