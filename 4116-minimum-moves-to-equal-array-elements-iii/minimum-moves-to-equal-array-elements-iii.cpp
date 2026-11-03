class Solution {
public:
    int minMoves(vector<int>& nums) {
    int max1 = INT16_MIN;
    int c =0;

    for (int i = 0; i < nums.size(); i++)
    {
        max1=max(max1,nums[i]);
    }
    
    for (int i = 0; i < nums.size(); i++)
    {
        while(nums[i]!=max1){
            c++;
            nums[i]++;
        }
    }
    
    return c;
    
}
};