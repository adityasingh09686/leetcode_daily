class Solution {
public:
    int helper(vector<vector<int>>& dp, vector<int>& arr, int sum, int i) {
        if (sum == 0) {
            return 1;
        }

        if (sum < 0 || i == arr.size()) {
            return 0;
        }

        if (dp[i][sum] != (-1)) {
            return dp[i][sum];
        }

        int pick = helper(dp, arr, sum - arr[i], i + 1);
        int notpick = helper(dp, arr, sum, i + 1);

        return dp[i][sum] = (pick || notpick);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // odd ones are rejected
        if (sum % 2 == 1) {
            return false;
        }

        vector<vector<int>> dp(n+1,vector<int>(sum/2+1,-1));

        return helper(dp,nums,sum/2,0);
    }
};