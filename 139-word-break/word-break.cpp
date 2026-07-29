class Solution {
public:
    bool helper(int idx, vector<int>& dp, string s, int n,
                vector<string>& wordDict) {
        if (idx == n) {
            return true;
        }

        if (dp[idx] != (-1)) {
            return dp[idx];
        }

        for (int i = 0; i < wordDict.size(); i++) {
            int len = wordDict[i].size();
            if ((len + idx) <= n && s.substr(idx, len) == wordDict[i]) {
                if (helper(idx + len, dp, s, n, wordDict))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return helper(0, dp, s, n, wordDict);
    }
};