class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int exp = k;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==exp){
                exp+=k;
            }
        }

        return exp;
    }
};