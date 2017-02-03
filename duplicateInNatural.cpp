class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int fast = 0;
        int slow = 0;
        
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            cout << slow << " "<<fast<<endl;
            if(slow  == fast){
                cout << "here " << endl;
                slow = 0;
                while(slow!=fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
        return -1;
    }
};