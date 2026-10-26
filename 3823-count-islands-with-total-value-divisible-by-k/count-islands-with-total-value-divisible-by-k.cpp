class Solution {
public:
    bool isSafe(vector<vector<int>>& grid,
                vector<vector<bool>>& vis,
                int i, int j, int n, int m) {
        return i >= 0 && i < n &&
               j >= 0 && j < m &&
               grid[i][j] != 0 && !vis[i][j];
    }

    // Changed return type from int to long long
    long long dfs(vector<vector<int>>& grid,
            vector<vector<bool>>& vis,
            int i, int j, int n, int m) {

        vis[i][j] = true;
        long long int sum = grid[i][j];

        int l[4] = {-1, 0, 1, 0};
        int r[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int x = i + l[k];
            int y = j + r[k];

            if (isSafe(grid, vis, x, y, n, m)) {
                sum += dfs(grid, vis, x, y, n, m);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty() || k <= 0)
            return 0;

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && !vis[i][j]) {
                    long long int xham = dfs(grid, vis, i, j, n, m);

                    if (xham % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};