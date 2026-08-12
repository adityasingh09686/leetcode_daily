class Solution {
public:
    bool isSafe(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i,
                int j, vector<vector<bool>>& vis) {
        int n = grid1.size();
        int m = grid1[0].size();

        return i < n && i >= 0 && j < m && j >= 0 && !vis[i][j] &&
               grid2[i][j] == 1;
    }
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i,
             int j, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        int a[4] = {-1, 0, 1, 0};
        int b[4] = {0, 1, 0, -1};
        bool result = (grid1[i][j] == 1);
        for (int k = 0; k < 4; k++) {
            int x = i + a[k];
            int y = j + b[k];
            if (isSafe(grid1, grid2, x, y, vis)) {
                if (!dfs(grid1, grid2, x, y, vis)) {
                    result = false;
                }
            }
        }
        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid2[0].size();
        vector<vector<bool>> vec(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && !vec[i][j]) {
                    if (dfs(grid1, grid2, i, j, vec)) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};