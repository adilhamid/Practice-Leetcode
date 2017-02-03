class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        unordered_map<string, int> count;
        
        for(string str:words){
            count[str]++;
        }
        
        int len = s.length();
        int num = words.size();
        int wordLen = words[0].size();
        vector<int> result;
        
        for(int i =0; i< len - num*wordLen+1; i++){
            unordered_map<string, int> seenWords;
            int j =0;
            for( ; j<num; j++ ){
                string word = s.substr(i+j*wordLen, wordLen);
                if(count.find(word)!=count.end()){
                    seenWords[word]++;
                    if(seenWords[word]>count[word])
                    break;
                }
                else
                    break;
            }
            if(j == num) result.push_back(i);
        }
        
        return result;
    }
};