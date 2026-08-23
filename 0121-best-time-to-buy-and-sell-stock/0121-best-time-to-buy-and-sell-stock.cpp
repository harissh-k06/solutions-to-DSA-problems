class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        if (days == 0) return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int p = 1; p < days ; p++){
            int hypProfit = prices[p] - minPrice; //hypothetical Profit at any point in time
            if (hypProfit >  0){
                if (maxProfit < hypProfit){
                    maxProfit = hypProfit;
                }
            }else{
                minPrice = prices[p];
            }
        }
        return maxProfit;

    }
};