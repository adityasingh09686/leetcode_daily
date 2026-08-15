class Solution {
public:
    int longestSubsequence(vector<int>& nums){
        sort(nums.begin(),nums.end());
        if(nums[nums.size()-1] == 0){
            return 0;
        }
        map<int,int> mp;
        int k = 0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            k = nums[i]^k;
        }

        if(k==0){
            return nums.size()-1;
        }

        int x = 0;
        // for(int i=0;i<nums.size();i++){
        //     if(mp[nums[i]]%2 == 0){
        //         x++;
        //     }
        // }

        return nums.size()-x;
    }
};