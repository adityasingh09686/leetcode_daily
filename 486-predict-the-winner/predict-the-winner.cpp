class Solution {
public:
    // bool helper(int l, int r, int s1, int s2,bool b ,vector<int>& nums) {
    //     if (l > r) {
    //         // return if the score of player 1 is greater than that of player 2
    //         return s1>=s2;
    //     }

    //     bool x,y,z,m;
    //     if(b){
    //         x = helper(l+1)
    //         y = helper()
    //     }
    //     else{

    //     }

    //     return ;
    // }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        if(n%2 == 0){
            return true;
        }

        vector<int> dp(nums);

        for(int i=n-2;i>=0;--i){
            for(int j=i+1;j<n;++j){
                dp[j] = max(nums[i] - dp[j],nums[j]-dp[j-1]);
            }
        }

        return dp[n-1]>=0;
    }
};