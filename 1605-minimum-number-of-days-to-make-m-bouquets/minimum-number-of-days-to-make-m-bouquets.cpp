class Solution {
public:
    int helper(vector<int>& bloomDay, int mid, int k){
        int l = 0,r = 0;
        int s = 0;
        int ans = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid>=bloomDay[i]){
                s++;
            }
            if(s == k){
                l = k;
                ans++;
                s = 0;
            }
            if(mid<bloomDay[i]){
                s=0;
            }
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k){
        if ((long long)m * k > bloomDay.size()) return -1; 
        int l = 1;
        int r = *max_element(bloomDay.begin(),bloomDay.end());
        int n = bloomDay.size();
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int a = helper(bloomDay,mid,k);
            if(a>=m){
                r = mid-1;
                ans = mid;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};