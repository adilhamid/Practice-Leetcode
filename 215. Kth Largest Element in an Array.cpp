class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return -1;
        
        priority_queue<int , vector<int>, greater<int>> myheap;
        
        for(int i =0; i<nums.size(); i++){
            if(myheap.size() < k){
                myheap.push(nums[i]);
            }
            else if(myheap.top() < nums[i]){
                myheap.pop();
                myheap.push(nums[i]);
            }
        }
        
        return myheap.top();
        
    }
};
