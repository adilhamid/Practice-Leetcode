#include<import.h>

class Solution {
public:
    string removeKdigits(string num, int k) {
        int drop = k;
        int len = num.length();
        cout << len <<endl;
        if(k >= len) return "0";
        vector<int> res;
        for(int i =0; i< len; i++){
            int numb = num[i] - '0';
            while(drop && !res.empty() && res.back() > numb){
                res.pop_back();
                drop--;
            }
            res.push_back(numb);
        }
        res.resize(len-k);
        
        // Output the Value in form of string.
        string output="";
        bool leadZero= true;
      
        for(int num:res){
            if(leadZero && num == 0){
                continue;
            }
            else{
                leadZero = false;
                 output += to_string(num);
            }
           
        }
        
        return output.empty()?"0":output;
        
    }
};