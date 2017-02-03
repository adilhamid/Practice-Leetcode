class RandomizedSet {

private:

unordered_map<int, int> numbers; // stores the key and the index of the val
vector<int> nums;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(numbers.find(val)!=numbers.end()){
            return false;
        }
        nums.push_back(val);
        numbers[val] = nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(numbers.find(val) == numbers.end())
            return false;
        
        int lastNum = nums.back();
        numbers[lastNum] = numbers[val];
        nums[numbers[val]] = lastNum;
        nums.pop_back();
        numbers.erase(val);

        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */