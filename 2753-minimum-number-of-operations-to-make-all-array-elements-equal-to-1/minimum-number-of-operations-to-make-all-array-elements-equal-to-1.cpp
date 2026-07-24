class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int g = nums[0];
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                ones++;
            }
            g = gcd(g, nums[i]);
        }

        if (g > 1) {
            return -1;
        }

        if (ones > 0) {
            return n - ones;
        }
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = i + 1; j < n; j++) {
                x = gcd(x, nums[j]);
                if (x == 1) {
                    mini = min(mini, j - i + 1);
                    break;
                }
            }
        }

        if(mini!=INT_MAX){
            return mini + n-2;
        }

        return -1;
    }
};