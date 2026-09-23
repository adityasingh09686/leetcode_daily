class Solution {
public:
    // recurrsive soln
    // int helper(vector<int>& nums,int i,int j,int x){
    //     if(x==0){
    //         return 0;
    //     }

    //     if(i>j){
    //         return 1e9;
    //     }

    //     // take from left 
    //     int a = helper(nums,i+1,j,x-nums[i])+1;
    //     // take from right 
    //     int b = helper(nums,i,j-1,x-nums[j])+1;

    //     return min(a,b);
    // }
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int t = 0;
        for(int i=0;i<n;i++){
            t+=nums[i];
        }
        t = t - x;
        int s = 0;
        int minlen = -1;
        for(r=0;r<n;r++){
            s+=nums[r];
            while(l<=r && s>t){
                s-=nums[l];
                l++;
            }
            if(s==t){
                minlen = max(minlen,r-l+1);
            }
        }

        if(minlen == -1){
            return -1;
        }

        return n - minlen;
    }
};