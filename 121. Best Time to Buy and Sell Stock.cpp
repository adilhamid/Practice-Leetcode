class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX;
        int maxProfit = 0;
        int len = prices.size();
        
        for(int i =0; i<len; i++ ){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        
        return maxProfit;
        
    }
};