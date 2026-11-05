class Solution {
public:
    // int helper(vector<int>& nums, int i, int start, vector<int>& dp) {

    //     if (i < start) {
    //         return 0;
    //     }

    //     if (i == start) {
    //         return nums[i];
    //     }
    //     if (dp[i] != (-1)) {
    //         return dp[i];
    //     }
    //     int pick = nums[i] + helper(nums, i - 2, start, dp);
    //     int notpick = 0 + helper(nums, i - 1, start, dp);
    //     return dp[i] = max(pick, notpick);
    // }

    int helper(vector<int> vec, int s, int e) {
        int p1 = vec[s];
        int p2 = 0;
        for (int i = s + 1; i <= e; i++) {
            int pick = vec[i] + p2;
            int notpick = p1;
            int curr = max(pick, notpick);
            p1 = curr;
            p2 = notpick;
        }

        return p1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        // vector<int> dp1(n, -1);
        // vector<int> dp2(n, -1);
        int x = helper(nums, 0, n - 2);
        int y = helper(nums, 1, n - 1);
        return max(x, y);
    }
};