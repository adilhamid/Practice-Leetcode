class Solution {
    
private:
int rows;
int cols;

public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        if(!rows) return;
        cols = board[0].size();
        
        if(rows<3 || cols<3)
            return;
        
        for(int col =0; col<cols; ++col){
            if(board[0][col]=='O')
                BFSBOARD(board,0,col);
                
            if(board[rows-1][col]=='O')
                BFSBOARD(board,rows-1, col);
        }
        
         for(int row =0; row<rows; ++row){
            if(board[row][0]=='O')
                BFSBOARD(board,row,0);
                
            if(board[row][cols-1]=='O')
                BFSBOARD(board,row, cols-1);
        }
        
        for(int i =0 ; i<rows; i++){
            for(int j =0; j<cols; j++){
                if(board[i][j]!='X'){
                    board[i][j] = board[i][j]=='F'?'O':'X';
                }
            }
        }
        return;
    }
    
    void BFSBOARD(vector<vector<char>>& board,int i, int j){
        
        board[i][j]='F';
        
        queue<pair<int,int>> myQueue;
        myQueue.push(make_pair(i,j));
        
        while(!myQueue.empty()){
            int row = myQueue.front().first;
            int col = myQueue.front().second;
            myQueue.pop();
            
            //Now lets take four conditions of surroundings
            if(row>1 && board[row-1][col]=='O'){
                board[row-1][col]='F';
                myQueue.push(make_pair(row-1, col));
            }
            
             if(row<rows-2 && board[row+1][col]=='O'){
                board[row+1][col]='F';
                myQueue.push(make_pair(row+1, col));
            }
            
             if(col>1 && board[row][col-1]=='O'){
                board[row][col-1]='F';
                myQueue.push(make_pair(row, col-1));
            }
            
             if(col<cols-2 && board[row][col+1]=='O'){
                board[row][col+1]='F';
                myQueue.push(make_pair(row, col+1));
            }
        }
        return;
    }
};