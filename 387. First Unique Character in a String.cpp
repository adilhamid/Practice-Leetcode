class Solution {
public:
    int firstUniqChar(string s) {
        
        if(s.empty()) return -1;
        int len = s.length();
        int slow =0, fast =1;
        vector<int> map(256,0);
        map[s[slow]]++;
        while(fast < len){
            map[s[fast]]++;
            
            while(slow < len && map[s[slow]]>1) slow++;
            if(slow>= len) return -1;
            
            if(map[s[slow]] == 0){
                map[s[slow]]++;
                fast = slow;
            }
            fast++;
        }
        return slow;
    }
};




//A;ternative 
class Solution {
public:
    int firstUniqChar(string s) {
        
        if(s.empty()) return -1;
        unordered_map<char, pair<int,int>> map;
        
        for(int i =0; i< s.length(); i++){
            map[s[i]].first++;
            map[s[i]].second = i;
        }
        int idx = s.size();
        for(auto p : map){
            if(p.second.first ==1) idx = min(idx, p.second.second);
        }
        return idx==s.size()? -1: idx;
    }
};