class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> curr(n,0);
        
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        
        for(int i =0; i< n ; i++){
            if(!obstacleGrid[0][i])
                curr[i] = 1;
            else
                break;
        }
        
        bool sumCheck;
        
        for(int i =1; i<m ;i++){
            sumCheck = false;        
            if(obstacleGrid[i][0]){
             curr[0] =0;
            }
            else sumCheck = true;
            
            for(int j =1; j<n; j++){
               if(obstacleGrid[i][j]){
                    curr[j] =0;
                }
                else{ 
                    curr[j] += curr[j-1];
                    if(curr[j]) sumCheck = true;
                }
                
                
            }
           if(!sumCheck) return 0;
        }
        
        return curr[n-1];
        
    }
};