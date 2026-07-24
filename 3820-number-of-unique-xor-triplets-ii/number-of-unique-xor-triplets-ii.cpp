class Solution {
public:
// ai se chapa hain bkl
    int uniqueXorTriplets(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        // if(n==1 || n==2){
        //     return n;
        // }
        
        // nums[i] max -> 1500 -> max xor value = 2048 (all are ones)
        int maxi = 2048;
        vector<bool> pair_xors(maxi,false);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pair_xors[nums[i]^nums[j]]=true;
            }
        }

        int ans = 0;
        vector<bool> triplepairs(maxi,false);

        for(int i=0;i<n;i++){
            for(int j=0;j<maxi;j++){
                if(pair_xors[j]){
                    int x = j^nums[i];
                    if(!triplepairs[x]){
                        ans++;
                        triplepairs[x] = true;
                    }
                }
            }
        }

        return ans;
    }
};