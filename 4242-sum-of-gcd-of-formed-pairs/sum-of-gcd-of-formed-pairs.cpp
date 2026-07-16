class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int maxi = nums[0];
        
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi); 
        }
        
        sort(prefixGcd.begin(), prefixGcd.end());
        
        long long ans = 0;
    
        for(int i = 0; i < n / 2; i++) {
            ans += gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
        }
        
        return ans;
    }
};
