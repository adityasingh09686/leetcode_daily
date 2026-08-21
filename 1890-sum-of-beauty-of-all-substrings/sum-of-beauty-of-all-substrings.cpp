class Solution {
public:
    int helper(unordered_map<char,int>& mp){
        int mini = INT_MAX;
        int maxi = 0;
        for(auto& p:mp){
            mini = min(mini,p.second);
            maxi = max(maxi,p.second);
        }
        return maxi-mini;
    }
    int beautySum(string s){
        int  n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                ans+=helper(mp);
            }
        }

        return ans;
    }
};