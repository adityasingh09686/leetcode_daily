class Solution {
public:
    int minMoves2(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int med = 0;
        if((n%2) == 0){
            med = med + (nums[(n/2)-1]+nums[n/2])/2;
        }
        else{
            med = med + nums[n/2];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=abs(nums[i]-med);
        }

        return ans;
    }
};