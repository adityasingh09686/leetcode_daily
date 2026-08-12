class Solution {
public:
    int findPeakElement(vector<int>& nums){
        nums.push_back(INT_MIN);
        nums.insert(nums.begin(),INT_MIN);
        int n = nums.size();
        int l = 1;
        int r = n-2;

        if(n == 3  && nums[1]==INT_MIN){
            return 0;
        }

        if(nums[1]>nums[0] && nums[1]>nums[2]){
            return 0;
        }

        if(nums[n-2]>nums[n-1] && nums[n-2]>nums[n-3]){
            return n-3;
        }

        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid-1;
            }
            if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        return -1;
    }
};