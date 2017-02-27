class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        int cols = rows? grid[0].size(): 0;
        
        if(!rows && !cols) return 0;
        
        int count = 2;
        for(int i =0; i< rows; i++){
            for(int j =0; j<cols; j++){
                if(grid[i][j] =='1'){
                    char val = count + '0';
                    DFSGRID(grid, i, j,val);
                    count++;
                }
                
            }
        }
        
        return count -  2;
        
    }
    
    void DFSGRID(vector<vector<char>>& grid , int i, int j, char val){
        if(i<0 || i>=grid.size() || j<0 || j>= grid[0].size() || grid[i][j]!='1') 
            return;
        grid[i][j] = val;
        
        //Check all the four adjacencies for DFS Search
        DFSGRID(grid, i, j-1, val);
        DFSGRID(grid, i, j+1, val);
        DFSGRID(grid, i-1, j, val);
        DFSGRID(grid, i+1, j, val);
        
        return;
    }
};