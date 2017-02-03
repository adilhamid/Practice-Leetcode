class RandomizedCollection {

private:

unordered_map<int, vector<int>> numbers; // stores the key and the index of the val
vector<int> nums;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        numbers[val].push_back(nums.size()-1);
        return numbers[val].size()==1;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(numbers[val].empty())
            return false;
        
        int idx = numbers[val].back();
        numbers[val].pop_back();

        if(nums.size() - 1 != idx)
        {
            int tmp = nums.back();
            int indexNum = nums.size()-1;
            int i=numbers[tmp].size()-1;
            while(numbers[tmp][i]!=indexNum){
                i--;
            }
            nums[idx] = tmp;
            numbers[tmp][i] = (idx);
        }
        nums.pop_back();
        return true;
    
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */