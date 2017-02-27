class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if(!len) return false;
        
        vector<int> LPS = generateLPS(s);
        
        return (LPS[len-1] > 0 && len %(len-LPS[len-1]) == 0);
    }
    
    vector<int> generateLPS(string str){
        int size = str.length();
        
        vector<int> LPS(size);
        LPS[0] = 0;
        
        int i =1; 
        int length =0;
        
        while(i< size){
            if(str[i] == str[length]){
                length++;
                LPS[i] = length;
                i++;
            }
            else{
                if(length!=0){
                    length = LPS[length-1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        return LPS;
    }
};