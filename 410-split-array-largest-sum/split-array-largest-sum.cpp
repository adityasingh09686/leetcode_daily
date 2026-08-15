class Solution {
public:
    int helper(vector<int>& nums, int k,int mid,int maxi){
        int p = 1;
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(sum + nums[i] <=maxi){
                sum+=nums[i];
            }
            else{
                sum = nums[i];
                p++;
            }
        }
        return p;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        while(l<=r){
            int mid = l + (r-l)/2;
            int part = helper(nums, k, mid, mid);
            if(part>k){
                l = mid+1;
            }
            else{
                r = mid - 1;
            }
        }

        return l;
    }
};