class Solution {
public:
    bool isScramble(string s1, string s2) {
       int len1 = s1.length(), len2 = s2.length();
       if(len1 != len2) return false;
       
       if( s1 == s2) return true;
       
       vector<int> table(26, 0);
       
       for(int i =0; i< len1; i++){
            table[s1[i]-'a']++;
            table[s2[i]-'a']--;
       }   
       
        for(int num : table){
            if(num != 0 ) 
                return false;
        }
        
        // Now To check the scrambling part;
        
        //using the Recursion
        for(int i =1; i< len1; i++){
            if( isScramble(s1.substr(0,i) , s2.substr(0,i)) && isScramble(s1.substr(i) , s2.substr(i))) 
                return true;
            if(isScramble(s1.substr(0,i) , s2.substr(len1-i)) && isScramble(s1.substr(i), s2.substr(0,len1-i)))
                return true;
        }
        
        
        return false;
    }
};