class Solution {
public:
    int minInsertions(string s) {
        string text1 = s;
        reverse(s.begin(), s.end());
        string text2 = s;
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }

        return n - dp[n][n];
    }
};