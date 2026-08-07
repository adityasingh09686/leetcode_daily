class Solution {
public:
    int maxDigitRange(vector<int>& nums){
        int maxi = 0;
        int x = 0;
        for(int i=0;i<nums.size();i++){
            string s = to_string(nums[i]);
            sort(s.begin(),s.end());
            int ans = s[s.size()-1]- s[0];
            if(ans>maxi){
                maxi = ans;
                x = nums[i];
            }
            else if(ans == maxi){
                x+=nums[i];
            }
        }

        return x;
    }
};