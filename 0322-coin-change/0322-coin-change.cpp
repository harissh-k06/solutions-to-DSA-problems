class Solution {
   public:
    unordered_map<int, int> minimumTrack;
    int helper(vector<int>& coins, int target) {
        if (target == 0) {
            minimumTrack[target] = 0;
            return 0;
        }
        if (minimumTrack.count(target)) return minimumTrack[target];
        int minimumCoins = INT_MAX;
        for (int coin : coins) {
            if (coin > target) continue;
            int newTarget = target - coin;
            int minCoinsForNew = helper(coins, newTarget);
            if (minCoinsForNew != -1) {
                minimumCoins = min(minimumCoins, 1 + minCoinsForNew);
            }
        }
        minimumTrack[target] = minimumCoins == INT_MAX ? -1 : minimumCoins;
        return minimumCoins == INT_MAX ? -1 : minimumCoins;
    }

   public:
    int coinChange(vector<int>& coins, int amount) { return helper(coins, amount); }
};
