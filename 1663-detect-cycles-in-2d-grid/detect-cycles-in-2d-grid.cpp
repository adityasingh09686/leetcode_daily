class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, pair<int, int>>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    q.push({{i, j}, {-1, -1}});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        auto p = q.front();
                        int u = p.first.first;
                        int v = p.first.second;
                        int pu = p.second.first;
                        int pv = p.second.second;
                        int a[4] = {-1, 0, 1, 0};
                        int b[4] = {0, 1, 0, -1};
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            int x = u + a[i];
                            int y = v + b[i];
                            if (x >= 0 && x < n && y >= 0 && y < m &&
                                grid[x][y] == grid[u][v]) {

                                if (!vis[x][y]) {
                                    vis[x][y] = 1;
                                    q.push({{x, y}, {u, v}});
                                } else if (x != pu || y != pv) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
};