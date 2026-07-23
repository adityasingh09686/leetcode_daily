class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        // if the values is 1 and 2 
        if(n == 1 || n==2 ){
            return n;
        }

        // if the n>=3 then all possible can be obtained from 1 to n;
        int  p = 1;
        while(p<=n){
            p<<=1;
        }

        return p;
    }
};