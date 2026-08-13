class Solution {
public:
    int helper(vector<int>& vec, int w) {
        int s = 0;
        int ans = 1;
        for (int i = 0; i < vec.size(); i++) {
            s += vec[i];
            if (s > w) {
                ans++;
                s = vec[i];
            }
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int r = 0;
        for (int i = 0; i < weights.size(); i++) {
            r += weights[i];
        }
        int l = *max_element(weights.begin(), weights.end());
        ;
        int x = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int t = helper(weights, mid);
            if (t <= days) {
                x = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return x;
    }
};