class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](auto& a, auto& b) {
                 return a[1] < b[1];
             });

        vector<pair<int,int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());
        vector<int> freq(n + 1, 0);

        int l = 0, r = 0;
        int active = 0;
        int sz = logs.size();

        for (auto [t, idx] : q) {
            int a = t - x;
            int b = t;

            while (r < sz && logs[r][1] <= b) {
                int id = logs[r][0];

                if (freq[id] == 0) active++;
                freq[id]++;
                r++;
            }

            while (l < r && logs[l][1] < a) {
                int id = logs[l][0];

                freq[id]--;
                if (freq[id] == 0) active--;
                l++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};