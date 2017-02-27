class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.empty() && t.empty()) return true;
        vector<int>map(256,0);
        
        if(s.length() != t.length()) return false;
        
        for(int len =0; len<s.length();len++ ){
            map[s[len]]++;
            map[t[len]]--;
        }
        
        for(auto val : map){
            if(val != 0) return false;
        }
        
        return true;
    }
};