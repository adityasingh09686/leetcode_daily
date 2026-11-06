class Solution {
public:
    int helper(vector<int>& coins, int sum, int i, vector<vector<int>>& dp) {
        if (sum == 0) {
            return 1;
        }
        if (sum < 0 || i == coins.size()) {
            return 0;
        }

        if (dp[i][sum]!=(-1)){
            return dp[i][sum];
        }

        int take = helper(coins, sum - coins[i], i,dp);

        int nottake = helper(coins, sum, i + 1,dp);

        return dp[i][sum] = take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return helper(coins, amount, 0,dp);
    }
};