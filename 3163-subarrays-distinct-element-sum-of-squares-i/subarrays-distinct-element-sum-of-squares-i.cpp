class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            map<int, int> mp;
            for (int j = i; j < n; j++) {
                mp[nums[j]]++;
                ans = ans + mp.size() * mp.size();
            }
        }

        return ans;
    }
};