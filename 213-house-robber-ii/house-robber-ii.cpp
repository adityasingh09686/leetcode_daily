class Solution {
public:
    int helper(vector<int>& nums, int i, int start, vector<int>& dp) {

        if (i < start) {
            return 0;
        }

        if (i == start) {
            return nums[i];
        }
        if (dp[i] != (-1)) {
            return dp[i];
        }
        int pick = nums[i] + helper(nums, i - 2, start, dp);
        int notpick = 0 + helper(nums, i - 1, start, dp);
        return dp[i] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int x = helper(nums, n - 2,0, dp1);
        int y = helper(nums, n - 1,1, dp2);

        return max(x, y);
    }
};