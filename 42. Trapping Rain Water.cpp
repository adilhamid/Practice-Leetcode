class Solution {
public:
    
        int trapII(vector<int>& nums) {
        
        int size = nums.size();
        if(!size) return 0;
        int start = 0; 
        int end = size-1;
        
        int waterHold = 0;
        int level = 0;
        
        while(start<end){
            
            int lower = nums[start] < nums[end] ? nums[start++] : nums[end--];
            level = max(lower, level);
            waterHold += (level - lower);
        }
        
        return waterHold;
         
        
    }
       
    int trap(vector<int>& nums){
        int size = nums.size();
        if(!size) return 0;
        
        stack<int> myStack;
        int maxWater =0; int maxWaterHere = 0;
        
        for(int i =0; i< size;){
            if(myStack.empty() || nums[myStack.top()] >= nums[i]){
                myStack.push(i++);
            }    
            else{
                while(!myStack.empty() && nums[myStack.top()] < nums[i]){
                    int rem = myStack.top();
                    myStack.pop();
                
                    maxWaterHere = myStack.empty() ? 0 : ((min(nums[myStack.top()],nums[i]) - nums[rem]) * (i - myStack.top()-1));
                    maxWater += maxWaterHere;
                }
            }
        }
        return maxWater;
    }
    
};