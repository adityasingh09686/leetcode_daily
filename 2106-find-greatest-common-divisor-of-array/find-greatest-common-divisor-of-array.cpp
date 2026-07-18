class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1){
            return nums[0];
        }

        return gcd(nums[0],nums[nums.size()-1]);
    }
};