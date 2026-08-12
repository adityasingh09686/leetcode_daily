class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mp;
        int l = 0,r=0;
        int maxi = 0;
        for(r=0;r<nums.size();r++){
            mp[nums[r]]++;
            while(mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);
        }

        return maxi;
        
    }
};