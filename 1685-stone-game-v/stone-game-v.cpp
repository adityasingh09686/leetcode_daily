class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pre(n+1,0);

        for(int i=0;i<n;i++){
            pre[i+1] = pre[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j = i + len - 1;

                // for the partition of the element 
                for(int k=i;k<j;k++){
                    int l =
                        pre[k + 1] - pre[i];

                    int r =
                        pre[j + 1] - pre[k + 1];

                    if(l<r){
                        dp[i][j] = max(
                            dp[i][j],
                            l + dp[i][k]
                        );
                    }
                    else if(l>r){
                        dp[i][j] = max(
                            dp[i][j],
                            r + dp[k+1][j]
                        );
                    }
                    else{
                        dp[i][j] = max(l + dp[i][k],r+dp[k+1][j]);
                    }
                }
            }
        }

        return dp[0][n-1];
    }
};