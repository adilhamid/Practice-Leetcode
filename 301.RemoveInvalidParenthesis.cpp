class Solution {
public:
    vector<string> removeInvalidParentheses(string str) {
        vector<string> result;
        helperFunc(str, result, 0 , 0 ,"()");
        return result;
    }
    
    void helperFunc(string str, vector<string>&result, int last_i, int last_j, string par){
        for(int start = 0, i=last_i; i<str.length(); i++){
            if(str[i] == par[0]) start++;
            if(str[i] == par[1]) start--;
            
            if(start>=0) continue;
            
            for(int j =last_j; j<=i; j++){
                if(str[j] == par[1] && (j== last_j || str[j-1] != par[1])){
                    helperFunc(str.substr(0, j) + str.substr(j + 1, str.length()),result, i, j,par);
                }
            }
            return;
        }
            
        string revStr = str;
        reverse(revStr.begin(),revStr.end());
        if (par[0] == '(')
            helperFunc(revStr, result, 0, 0, ")(");
        else 
            result.push_back(revStr);
            
    }
};