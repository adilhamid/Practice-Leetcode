class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        if(len<=1) return {};
        
        auto lower = upper_bound(numbers.begin(), numbers.end(), target);
        int end_pointer;
        if(lower == numbers.end())
            end_pointer = lower - numbers.begin()-1;
        else
          end_pointer = lower - numbers.begin();
     
        int start_pointer = 0;
        
        while(start_pointer < end_pointer){
            
            if(numbers[start_pointer] + numbers[end_pointer] < target){
                start_pointer++;
            }
            else if(numbers[start_pointer] + numbers[end_pointer] > target){
                end_pointer--;
            }
            
            else{
                break;
            }
            
        }
        
        vector<int>result(2);
        result[0]= start_pointer+1;
        result[1]= end_pointer+1;
        return result;
        
    }
    
};