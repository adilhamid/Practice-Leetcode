class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if( digits.empty()) return {};
        
        vector<string> result;
        
        const vector<string> map = {"","", "abc", "def","ghi", "jkl","mno","pqrs","tuv","wxyz"};
        result.push_back("");
        
        for(int i=0; i< digits.size(); i++){
            int num = digits[i]-'0';
            
            if(num<0 && num>9) break;
            
            const string& candidate = map[num];
            if(candidate.empty()) continue;
            vector<string> temp;
            
            for(int j =0; j<candidate.size(); j++){
                for(int k =0; k< result.size(); k++){
                    temp.push_back(result[k] + candidate[j]);
                }
            }
            result.swap(temp);
        }
        
        return result;
        
    }
};