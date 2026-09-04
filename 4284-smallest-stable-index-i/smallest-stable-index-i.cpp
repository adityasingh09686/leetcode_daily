class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> a(n, 0), b(n, 0);

        int maxi = nums[0];
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            a[i] = maxi; 
        }

        int mini = nums[n-1];
        for(int i = n - 1; i >= 0; i--) {
            mini = min(mini, nums[i]);
            b[i] = mini; 
        }

        for(int i = 0; i < n; i++) {
            if((a[i] - b[i]) <= k) {
                return i;
            }
        }
        
        return -1;
    }
};