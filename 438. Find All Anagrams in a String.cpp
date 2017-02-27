//Alternate Solution

vector<int> findAnagrams(string s, string p) {
        
        vector<int> pv(256,0), , res;
        if(s.size() < p.size())
           return res;
        // Check fill up the vectors and match

        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]];
        }
        int start =0, end=0, count = p.length();

        while(end<s.length())
        {
            if(end-start == p.length() && pv[s[start++]]++> =0 ) 
                count++;

            if(--pv[s[end++]]>=0)
                count--;
            
            if(count == 0)
               res.push_back(start);
        }
        return res;
    }



//Basic Solution

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(256,0), sv(256,0), res;
        if(s.size() < p.size())
           return res;
        // Check fill up the vectors and match

        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]];
            ++sv[s[i]];
        }
        if(pv == sv)
           res.push_back(0);
       
       //Sliding Window based matching

        for(int i = p.size(); i < s.size(); ++i)
        {
            ++sv[s[i]]; // add new one
            --sv[s[i-p.size()]]; // remove the last index
            if(pv == sv)
               res.push_back(i-p.size()+1);
        }
        return res;
    }
}; 