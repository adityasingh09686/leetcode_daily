class Solution {
public:
    bool uniformArray(vector<int>& nums1){
        int n = nums1.size();
        int e1 = INT_MAX;
        int o1 = INT_MAX;

        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                e1 = min(e1,nums1[i]);
            }
            else{
                o1 = min(o1,nums1[i]);
            }
        }

        if(e1 == INT_MAX || o1 == INT_MAX){
            return true;
        } 

        bool a = false;
        bool b = false;

        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                if((nums1[i]-o1)<0){
                    return false;
                }
            }
        }

        return true;
    }
};