class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) return 0;

        // If k >= n / 2, we can make as many transactions as we want
        if (k >= n / 2) {
            int max_profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    max_profit += prices[i] - prices[i - 1];
                }
            }
            return max_profit;
        }

        vector<int> buy(k + 1, -1e9);
        vector<int> sell(k + 1, 0);

        for (int price : prices) {
            for (int t = 1; t <= k; ++t) {
                buy[t] = max(buy[t], sell[t - 1] - price);
                sell[t] = max(sell[t], buy[t] + price);
            }
        }

        return sell[k];
    }
};
