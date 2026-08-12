class Solution {
public:
    int helper(int end,int n,vector<vector<int>>& vec){
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while(l<=r){
            int mid = l + (r - l) / 2;
            if(vec[mid][0] >= end){
                ans = vec[mid][2];
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        for(int i=0;i<intervals.size();i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        if(n == 1  && intervals[0][0] == intervals[0][1]){
            return {0};
        }
        if(n == 1){
            return {-1};
        }
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            int x = helper(intervals[i][1],n,intervals);
            vec[intervals[i][2]] = x;
        }

        return vec;
    }
};