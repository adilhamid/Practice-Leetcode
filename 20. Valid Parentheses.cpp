class Solution {
    
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        
        if (s.length() % 2 != 0)
		    return false;
        
        unordered_map<char, char> validmap;
        validmap['('] = '1';
        validmap['{'] = '2';
        validmap['['] = '3';
        validmap[')'] = '1';
        validmap['}'] = '2';
        validmap[']'] = '3';
        
        stack<char> mystack;
        
        for(int i =0; i< s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                mystack.push(validmap[s[i]]);
            }
            else{
                if(!mystack.empty() && mystack.top() == validmap[s[i]]){
                    mystack.pop();    
                }
                else
                    return false;
            }
        }
        
        return mystack.empty()? true: false;
        
    }
};