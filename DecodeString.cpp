

class Solution {
public:
    string decodeString(string s, int& i) {
       string result;
       
       while(i<s.length() && s[i]!=']'){
           if(!isdigit(s[i])){
               result+=s[i++];
           }
           else{
               int n =0;
                 while (i < s.length() && isdigit(s[i])){
                    n = n * 10 + s[i++] - '0'; 
                 }
                string t;
                i++;
                t = decodeString(s, i);
                i++;                
                while(n-- >0){
                    result += t;
                }
                    
            }
       }
        return result;
    }
    
     string decodeString(string s) {
        if(!s.length()) return "";
        int i =0;
        return decodeString(s,i);
     }
};