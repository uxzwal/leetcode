class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        
        // Loop through prices starting from the second day
        for (size_t i = 1; i < prices.size(); ++i) {
            // If the price increased compared to yesterday, harvest the profit
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        
        return max_profit;
    }
};
