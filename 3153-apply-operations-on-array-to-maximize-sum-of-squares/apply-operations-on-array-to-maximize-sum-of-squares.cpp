class Solution {
public:
    int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> vec(31,0);
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<31;j++){
                if((nums[i]>>j)&1){
                    vec[j]++;
                }
            }
        }

        long long int ans = 0;

        for(int j=0;j<k;j++){
            long long int x = 0;

            for (int i = 0; i < 31; i++) {
                if (vec[i]>0){
                    x|=(1LL<<i);
                    vec[i]--;
                }
            }
            ans = (ans + x*x)%MOD;
        }


        return ans;
    }
};