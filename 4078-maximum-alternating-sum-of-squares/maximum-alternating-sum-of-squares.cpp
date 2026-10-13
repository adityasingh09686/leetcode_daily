class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        long long int a = 0,b = 0;
        if(n%2!=0){
            int mid = n/2;
            for(int i=0;i<=mid;i++){
                a+=(nums[i]*nums[i]);
            }

            for(int i = mid+1;i<n;i++){
                b+=(nums[i]*nums[i]);
            }
        }
        else{
            for(int i=0;i<n/2;i++){
                a+=(nums[i]*nums[i]);
            }

            for(int i = n/2 ;i<n;i++){
                b+=(nums[i]*nums[i]);
            }
        }

        return a - b;
    }
};