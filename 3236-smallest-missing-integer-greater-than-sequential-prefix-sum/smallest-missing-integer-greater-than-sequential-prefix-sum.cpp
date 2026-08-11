class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // 1. Calculate the sum of the longest sequential prefix
        int prefixSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                prefixSum += nums[i];
            } else {
                break;
            }
        }
        unordered_set<int> numSet(nums.begin(), nums.end());
        while (numSet.count(prefixSum)) {
            prefixSum++;
        }
        
        return prefixSum;
    }
};
