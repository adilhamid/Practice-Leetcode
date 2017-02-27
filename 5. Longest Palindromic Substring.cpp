class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.length();
        
        //Manacher's Algorithm
        
        string str="";
        
        str +="$";
        for(auto val:s){
            str += "#";
            str += val;
        }
        str += "#@";
        
        int newlen = str.length();
        
        int R=0, C=0;
        
        int pall[newlen] = {0};
        
        for(int i=1; i<newlen-1; i++){
            int mirr = 2*C -i;
            
            if(i<R){
                pall[i] = min(R-i, pall[mirr]);
            }
            
            while(str[i+(1+pall[i])] == str[i-(1+pall[i])]){
                pall[i]++;
            }
            
            if( i + pall[i] > R){
                C = i;
                R = i + pall[i];
            }
            
        }
         len =0;
         int center =0;
            
            for( int i=0; i<newlen;i++){
                if(pall[i] > len){
                    len = pall[i];
                    center = i;
                }                    
            }
        
        return s.substr((center-1-len)/2, len);
        
        
    }
};