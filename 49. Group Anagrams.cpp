class Solution {
private:
unordered_map<string, int> mymap;
public:
    string CountSort(string str){
        vector<int> charmap(26,0);
        for(auto val: str){
            charmap[val-'a']++;
        }
        string res="";
        for(int i =0; i<26; i++){
            for(int j=0; j<charmap[i]; j++){
                res += i + 'a';
            }
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        if(!len) return {};
        
        vector<vector<string>> result;
        
        for(int i =0; i< len; i++){
            string temp = CountSort(strs[i]);
            if(mymap.find(temp) !=mymap.end()){
                result[mymap[temp]].push_back(strs[i]);
            }
            else{
                result.push_back({strs[i]});
                mymap[temp] = result.size()-1;
            }
        }
        
        return result;
    }
};