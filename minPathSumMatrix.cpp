class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        
        vector<int> curr(n);
        curr[0] = grid[0][0];
        for(int i=1; i< n; i++){
            curr[i] += curr[i-1] + grid[0][i];
        }
        
        for(int i =1; i< m; i++){
            for(int j =0; j<n; j++){
                if(j == 0){
                    curr[j] = curr[j] + grid[i][j];
                }
                else{
                    curr[j] = min(curr[j] + grid[i][j], curr[j-1]+grid[i][j]);
                }
            }
        }
        
        return curr[n-1];
     
    }
};