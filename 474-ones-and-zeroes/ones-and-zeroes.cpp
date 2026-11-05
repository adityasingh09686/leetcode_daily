class Solution {
public:
    int helper(int i, int x, int y, int m, int n,
               vector<vector<vector<int>>>& dp, vector<pair<int, int>>& p) {

        if (i == p.size())
            return 0;

        int zeros = p[i].first;
        int ones = p[i].second;

        if (dp[i][x][y] != (-1)) {
            return dp[i][x][y];
        }

        int pick = 0;
        if (x - zeros >= 0 && y - ones >= 0) {
            pick = 1 + helper(i + 1, x - zeros, y - ones, m, n, dp, p);
        }

        int notpick = helper(i + 1, x, y, m, n, dp, p);

        return dp[i][x][y] = max(pick, notpick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> vec;

        for (int i = 0; i < strs.size(); i++) {
            int a = 0, b = 0;

            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0')
                    a++;
                else
                    b++;
            }

            vec.push_back({a, b});
        }

        vector<vector<vector<int>>> dp(
            strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return helper(0, m, n, m, n, dp, vec);
    }
};