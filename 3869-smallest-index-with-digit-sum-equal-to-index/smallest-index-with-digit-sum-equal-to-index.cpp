class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = 0;
            int t = nums[i];
            while(nums[i]>0){
                x = x + nums[i]%10;
                nums[i] = nums[i]/10;
            }
            if(i==x){
                return i;
            }
        }

        return -1;
    }
};