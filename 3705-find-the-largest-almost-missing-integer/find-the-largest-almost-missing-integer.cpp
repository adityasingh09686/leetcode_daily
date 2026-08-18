class Solution {
public:
    void helper(map<int, int>& mp, vector<int>& nums, int l, int r) {
        for (int i = l; i <= r; i++) {
            mp[nums[i]]++;
        }
        return;
    }
    int largestInteger(vector<int>& nums, int k) {
        int mini = -1;
        unordered_map<int, int> mp;
        int n = nums.size();
        int l = 0;
        int r;
        for (int i = 0; i <= n-k; i++) {
            // track the unique elements
            unordered_set<int> s;
            for(int j=i;j<i+k;j++){
                s.insert(nums[j]);
            }

            for(auto& p:s){
                mp[p]++;
            }
        } 

        for (auto& p : mp) {
            if (p.second == 1) {
                mini = max(mini, p.first);
            }
        }

        return mini;
    }
};