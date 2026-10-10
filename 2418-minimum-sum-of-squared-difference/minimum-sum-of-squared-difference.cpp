class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        // vector<int> vec(nums1.size(),0);
        map<long long int, long long int> mp;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            mp[abs(nums1[i] - nums2[i])]++;
        }
        // sort(vec.begin(),vec.end());
        // reverse(vec.begin(),vec.end());
        // int t = k1+k2;

        // int x = 0;
        // while(t--){
        //     if(vec[x]>0){
        //     vec[x]--;
        //     }
        //     x = (x+1)%n;
        // }
        // long long ans = 0;
        // for(int i=0;i<n;i++){
        //     ans+=(vec[i]*vec[i]);
        // }
        long long t = k1 + k2;
        for (auto p = mp.rbegin(); p != mp.rend() && t > 0; ++p) {
            long long d = p->first;
            if (d == 0)
                break;
            long long f = p->second;
            long long x = min(t, f);
            // subbing the greatest
            mp[d] -= x;
            // adding the next greatest
            mp[d - 1] += x;
            t -= x;
        }

        long long ans = 0;
        for (auto& p : mp) {
            ans = ans + p.first * p.first * p.second;
        }

        return ans;
    }
};