class Solution {
public:
    int helper(vector<int>& coins,int amount,vector<int>& dp){
        if(amount == 0){
            return 0;
        }
        if(amount<0){
            return -1;
        }
        if(dp[amount]!=(-2)){
            return dp[amount];
        }
        int mini = 1e9;
        for(int i=0;i<coins.size();i++){
            int res = helper(coins,amount - coins[i],dp);
            if(res!=(-1)){
                mini = min(mini,1+res);
            }
        }
        return dp[amount] = mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> vec(amount+1,-2);
        int ans = helper(coins,amount,vec);

        return ans == 1e9 ? -1 : ans;
    }
};