class Solution {
public:
    int candy2P(vector<int>& ratings) {
        int len = ratings.size();
        
        if(!len) return 0;
        if(len == 1) return 1;
        
        vector<int> candyValues(len);
        candyValues[0] =1;
        for(int i =1; i< len; i++ ){
            if(ratings[i]> ratings[i-1]){
                candyValues[i] +=candyValues[i-1] + 1;
            }
            else{
                candyValues[i] = 1;
            }
        }
        int res = candyValues[len-1];
        for(int i = len-2; i>=0; i--){
            if(ratings[i] > ratings[i+1] && (candyValues[i] <= candyValues[i+1] )){
                candyValues[i] = candyValues[i+1] + 1;
              }
             res += candyValues[i];
        }
        return res;
    }
    
    //In One Pass
    
     int candy(vector<int>& ratings) {
         int len = ratings.size();
         if(len<=1) return len;
         
         int prev =1, countDown =0;
         int total = 1;
         
         for(int i =1; i<len; i++){
             
             if(ratings[i] >= ratings[i-1]){
                 if(countDown > 0){
                    total += countDown * (countDown+1) / 2; // total series sum while next is decreased ratings
                    if(countDown >= prev) total += countDown - prev + 1;
                    countDown =0;
                    prev = 1;
                 }
                 prev = ratings[i] == ratings[i-1]? 1 : prev+1;
                 total += prev;
                 
             }
             else{
                 countDown++;
             }
         }
         
         if(countDown >0){
              total += countDown * (countDown+1) / 2; // total series sum while next is decreased ratings
              if(countDown >= prev) total += countDown - prev + 1;
         }
        
         return total;
         
     }
    
};