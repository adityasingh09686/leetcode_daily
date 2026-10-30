
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        queue<int> q;

        for(int j = 0; j < n; j++) {
            if(vis[j] == -1) {
                q.push(j);
                vis[j] = 0;

                while(!q.empty()) {
                    auto p = q.front();
                    q.pop();

                    for(auto i : graph[p]) {
                        if(vis[i] == -1) {
                            vis[i] = !vis[p];
                            q.push(i);
                        }
                        else if(vis[i] == vis[p]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
