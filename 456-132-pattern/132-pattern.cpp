class Solution {
public:
    // int helper(){
    //     int l = start;
    //     int r = end;
    //     while(l<=r){
    //         int mid = l + (r-l)/2;
    //         if(nums[mid]<=)
    //     }
    //     // 3 1 4 2
    //     // -1 3 -1 4
    //     // -1 -1 1 1
    // }
    vector<int> greaterele(vector<int> vec) {
        int n = vec.size() - 1;
        stack<int> st;
        vector<int> ans(n + 1, INT_MIN);
        for (int i = n; i >= 0; i--) {
            while (!st.empty() && st.top() < vec[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(vec[i]);
        }

        return ans;
    }

    vector<int> nextsmallerele(vector<int> vec) {
        int n = vec.size() - 1;
        stack<int> st;
        vector<int> ans(n + 1, INT_MIN);
        for (int i = n; i >= 0; i--) {
            while (!st.empty() && st.top() > vec[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(vec[i]);
        }

        return ans;
    }
    bool find132pattern(vector<int>& nums) {
        int second = INT_MIN;
        stack<int> st;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            if(second>nums[i]){
                return true;
            }

            while(!st.empty() && st.top()<nums[i]){
                second = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;

        return false;
    }
};