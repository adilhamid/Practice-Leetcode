class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> hmap;
        int len = s.length();
        for(char c:s){
            hmap[c]++;
        }
        
        vector<vector<int>> bucketList(len+1);
        
        for(auto it = hmap.begin(); it!=hmap.end(); it++){
            int freq = it->second;
            bucketList[freq].push_back(it->first);
        }
        
        string result ="";
        for(int i=len ;i>=0 && result.length() <= len; i--){
            if(!bucketList.empty()){
                for(int k =0; k<bucketList[i].size();k++)
                    for(int l=0; l<i;l++)
                        result += bucketList[i][k];
                    if(result.length() == len)
                        break;
            }
        }
        return result;
    }
};