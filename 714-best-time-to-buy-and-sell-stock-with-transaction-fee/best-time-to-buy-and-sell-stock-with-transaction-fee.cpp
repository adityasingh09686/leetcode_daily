class Solution {
public:
    int helper(int i, int buy, vector<vector<int>>& dp, vector<int>& nums,int fee) {
    if (i >= nums.size()) {
        return 0;
    }

    if (dp[i][buy] != -1) {
        return dp[i][buy];
    }

    int profit = 0;
    if (buy == 1) {
        profit = max(helper(i + 1, 1, dp, nums,fee), -nums[i] + helper(i + 1, 0, dp, nums,fee) - fee);
    } else {
        profit = max(helper(i + 1, 0, dp, nums,fee), nums[i] + helper(i + 1, 1, dp, nums,fee));
    }

    return dp[i][buy] = profit;
}

int maxProfit(vector<int>& prices,int fee) {
    int n = prices.size();
    if (n <= 1) return 0;

    vector<vector<int>> dp(n, vector<int>(2, -1));
    return helper(0, 1, dp, prices,fee);
}
};