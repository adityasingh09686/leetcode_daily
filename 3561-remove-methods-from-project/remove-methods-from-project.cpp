class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<bool> vec(n + 1, false);
        vector<vector<int>> adj(n);
        for (int i = 0; i < invocations.size(); i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];
            adj[u].push_back(v);
        }

        queue<int> q;
        q.push(k);
        vec[k] = true;
        bool b = false;

        //  after this we know every suspicious node
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto& neighbour : adj[x]) {
                if (!vec[neighbour]) {
                    vec[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        // // now check every edge see if the outide->inside is possbile or not
        // for (int i = 0; i < invocations.size(); i++) {
        //     if (!vec[invocations[i][0]] && vec[invocations[i][1]]) {
        //         vec[invocations[i][1]] = false;
        //     }
        // }

        // pushing the nodes which are not in the link of outside->inside condition
        for (auto& e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!vec[u] && vec[v]) {
                vector<int> z;
                for (int i = 0; i < n; i++){
                    z.push_back(i);
                }
                return z;
            }
        }

        //
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vec[i])
                ans.push_back(i);
        }

        return ans;
    }
};