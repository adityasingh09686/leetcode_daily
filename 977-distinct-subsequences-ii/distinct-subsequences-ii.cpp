class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        vector<int> dp(26,0);
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            int idx = s[i]-'a';
            long long int x = (ans+1)%MOD;
            ans = (ans+x-dp[idx]+MOD)%MOD;
            dp[idx] = x;
        }

        return ans;
    }
};