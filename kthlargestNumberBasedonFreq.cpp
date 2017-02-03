#include "import.h"

class Solution {
public:

    vector<int> topKFrequentNthElement(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        
        for (const auto& i : nums) 
        {
            ++ counts[i];
        }
        
        vector<pair<int, int>> p;
        for (auto it = counts.begin(); it != counts.end(); ++ it) 
        {
            p.emplace_back(-(it->second), it->first);
        }
        
        nth_element(p.begin(), p.begin() + k - 1, p.end());
        vector<int> result;
        for (int i = 0; i < k; i++) 
        {
            result.emplace_back(p[i].second);
        }
        return result;
    }
        
        vector<int> topKFrequentBS(vector<int>& nums, int k) {
        
        unordered_map<int, int> mymap;
        for(int num:nums){
            mymap[num]++;
        }
        
        
        vector<vector<int>> bucket(nums.size()+1);
        
        for(auto it =mymap.begin(); it!=mymap.end(); ++it){
            int freq = it->second;
            bucket[freq].push_back(it->first);
        }
        vector<int> result;
        for (int pos = bucket.size() - 1; pos >= 0 && result.size() < k; pos--) {
            if (!bucket[pos].empty()) {
                for(int num:bucket[pos])
                    result.push_back(num);
                    if (result.size() == k)
                    break;
            }
        }
        cout << result.size() << endl;
        return result;
        
        
    
        
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mymap;
        for(int num:nums){
            mymap[num]++;
        }
        
        vector<int> result;
        priority_queue<pair<int,int >> pq;
        
        for(auto it =mymap.begin(); it!=mymap.end(); ++it){
             pq.push(make_pair(it->second, it->first));
            
             if(pq.size() > (int) mymap.size() - k){
                result.push_back(pq.top().second);
                pq.pop();
            }
        }
       
        return result;
        
        
    }
};