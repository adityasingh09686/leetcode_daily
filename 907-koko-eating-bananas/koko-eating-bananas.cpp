class Solution {
public:
    long long int helper(vector<int>& piles,int h){
        long long int t = 0;
        for(long long int i=0;i<piles.size();i++){
            t+=(piles[i]+h-1)/h;
        }
        return t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int n = piles.size();
        long long int l = 1;
        long long int r = INT_MAX;
        long long int ans = *max_element(piles.begin(),piles.end());

        while(l<=r){
            long long int mid = l + (r-l)/2;
            long long int t = helper(piles,mid);
            if(t<=h){
                ans = min(ans,mid);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;

    }
};