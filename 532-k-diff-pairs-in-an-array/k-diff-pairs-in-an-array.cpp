class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = n - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                long long diff = (long long)(abs(nums[i]-nums[mid]));
                if (diff == k) {
                    ans++;
                    break;
                } else if (diff > k) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        return ans;
    }
};