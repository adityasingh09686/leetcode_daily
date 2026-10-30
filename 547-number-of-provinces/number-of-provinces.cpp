class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int idx) {
        vis[idx] = 1;
        for (int j = 0; j < adj[idx].size(); j++) {
    if (adj[idx][j] == 1 && !vis[j]) {
        dfs(adj, vis, j);
    }
}
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected,vis,i);
                ans++;
            }
        }

        return ans;
    }
};