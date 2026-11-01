class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mini = nums[0];
        for(int i=1;i<n;i++){
            ans = ans + abs(nums[i]-nums[0]);
        }

        return ans;
    }
};