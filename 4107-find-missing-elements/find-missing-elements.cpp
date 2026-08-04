class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = nums[nums.size()-1];
        int mini = nums[0];
        vector<int> vec;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(int i=mini;i<=maxi;i++){
            if(mp[i]==0){
                vec.push_back(i);
            }
        }

        return vec;
    }
};