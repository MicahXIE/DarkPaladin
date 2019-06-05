
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() <= 0) return 0;
        
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for(int i =0 ;i<prices.size();i++){
            maxProfit = max(maxProfit,prices[i]-minPrice);
            minPrice = min(minPrice,prices[i]);
        }
        
        return maxProfit;
        
    }
};
