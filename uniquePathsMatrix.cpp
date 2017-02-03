class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1) return 1;
        
        if(m>n) swap(m,n);
        
        vector<int> cur(m,1);
        
        for(int j=1; j<n; j++){
            for(int i =1; i<m; i++){
                cur[i] += cur[i-1];
            }
        }
        
        return cur[m-1];
    }
};