class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                if(maxi!=-1){
                maxi = maxi&nums[i]&i;
                }
                else{
                    maxi = nums[i]&i;
                }
            }
        }

        return maxi == -1 ? 0:maxi;
    }
};