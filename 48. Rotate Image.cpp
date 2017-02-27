class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = rows? matrix[0].size():0;
        
        if(!rows && !cols) return;
        
        int k = rows/2;
        
        for(int layer =0 ; layer< k; layer++){
            int r = layer;
            int c =layer;
            
            for(int cnt =0; cnt < cols-1-(2*layer); cnt++){
                int tempval = matrix[r][c+cnt];
                matrix[r][c+cnt] =  matrix[rows-1-layer-cnt][c];
                matrix[rows-1-layer-cnt][c] = matrix[rows-1-layer][cols-1-layer-cnt];
                matrix[rows-1-layer][cols-1-layer-cnt] = matrix[r+cnt][cols-1-layer];
                 matrix[r+cnt][cols-1-layer] = tempval;
            }
            
        }
        
    }
};