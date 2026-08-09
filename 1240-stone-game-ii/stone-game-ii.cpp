class Solution {
public:
    int helper(int i, int m, vector<vector<int>>& dp, vector<int>& suff) {
        /// in case the no piles are left in the box
        if (i >= suff.size()-1) {
            return 0;
        }
        if (dp[i][m] != (-1)) {
            return dp[i][m];
        }

        int x = 0;
        for (int k = 1; k <= 2 * m && i + k < suff.size(); k++) {
            int y = suff[i] - helper(i+k, max(m,k), dp, suff);
            x = max(x, y);
        }
        return dp[i][m] = x;
    }
    int stoneGameII(vector<int>& piles) {
        vector<int> vec = piles;
        int n = piles.size();
        vector<int> suff(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suff[i] = piles[i] + suff[i + 1];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return helper(0, 1, dp, suff);
    }
};