bool isMatch(string s, string p) {
        return checkIsMatchIter(s,p);
    }
    
    bool checkIsMatchIter(string s, string p){
        int i,j, iSpec=-1, jSpec=-1;
        
        for(i =0, j=0; i<s.length();i++, j++){
            if(p[j]=='*'){
                iSpec = i;
                jSpec = j;
                i--;
            }
            else{
                if(s[i]!=p[j] && p[j]!='?'){
                    if(iSpec>=0){
                        i = iSpec++;
                        j = jSpec;
                    }
                    else return false;
                }
            }
        }
        
        while(p[j] == '*') ++j;
        
        return j==p.length();
    }