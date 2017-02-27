class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        
        vector<int> DICT(256,-1); //store the index of the character
        int start =-1;
        int maxLen = 0;
        
        for(int i =0; i< s.length(); i++){
            if(DICT[s[i]] > start){
                start = DICT[s[i]];
            }
            DICT[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};