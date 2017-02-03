class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
         if(!m && !n) return 0;
         if(!m) return n;
         if(!n) return m;
        
         vector<vector< int> > myDP(m+1,vector<int>(n+1,0));
        // //Initial Values for when second word is zero
         for(int i =1; i<=m; i++ ){
             myDP[i][0] = i;
          }
        // //Initial Values for when first word is zero
        for(int i =1; i<=n; i++ ){
            myDP[0][i] = i;
        }
        
        for(int i =1; i<=m; i++){
        
            for(int j=1; j<=n; j++){
                
                 if(word1[i-1] == word2[j-1]){
                     myDP[i][j] = myDP[i-1][j-1];
                 }
                 else{
                     myDP[i][j] = min(myDP[i-1][j-1] + 1,min( myDP[i-1][j]+1, myDP[i][j-1]+1));
                 }
            }
        }
        
         return myDP[m][n];
    }
};