class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec1;
        vector<int> vec2;
        vec1.push_back(nums[0]);
        vec2.push_back(nums[1]);
        int i=0,j=0,k=2;
        while(k<n){
            if(vec1[i]>vec2[j]){
                vec1.push_back(nums[k]);
                i++;
                k++;
            }else{
                vec2.push_back(nums[k]);
                j++;
                k++;
            }
        }
        vector<int> ans;

        for(int i=0;i<vec1.size();i++){
            ans.push_back(vec1[i]);
        }

        for(int i=0;i<vec2.size();i++){
            ans.push_back(vec2[i]);
        }

        return ans;
    }
};