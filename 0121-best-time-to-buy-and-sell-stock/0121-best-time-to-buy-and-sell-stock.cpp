class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int size = prices.size();
        int buyMin = prices[0];
        for (int i = 1 ; i < size ; i++){
            if (prices[i] < buyMin) buyMin = prices[i];
            else maxProfit = maxProfit > prices[i] - buyMin ? maxProfit : prices[i] - buyMin;
        }
        return maxProfit;
    }
};
