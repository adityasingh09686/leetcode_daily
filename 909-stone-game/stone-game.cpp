class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        if(n%2 == 0){
            return true;
        }

        vector<int> dp(piles);

        for(int i=n-2;i>=0;--i){
            for(int j=i+1;j<n;++j){
                dp[j] = max(piles[i] - dp[j],piles[j]-dp[j-1]);
            }
        }

        return dp[n-1]>=0;
    }
};