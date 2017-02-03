class Solution {
    
private:
vector<int> myNum;
public:
    Solution(vector<int> nums) {
       this->myNum = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return myNum;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> sArray(myNum);
        for (int i = 0; i < sArray.size(); i++)
        {
            int j = rand() % (sArray.size()-i);
            swap(sArray[i+j], sArray[i]);
        }
        
        return sArray;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */