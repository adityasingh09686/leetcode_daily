class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit){
        int n = nums.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({nums[i],i});
        }

        sort(vec.begin(),vec.end());

        vector<int> ans(n);
        int s = 0;
        while(s<n){
            int e = s;

            while (e + 1 < n &&
                   vec[e + 1].first - vec[e].first <= limit) {
                e++;
            }

            vector<int> ind;
            for(int i=s;i<=e;i++){
                ind.push_back(vec[i].second);
            }
            sort(ind.begin(),ind.end());

            for(int i=0;i<ind.size();i++){
                ans[ind[i]] = vec[i+s].first; 
            }
            s = e+1;
        }

        return ans;
     }
};