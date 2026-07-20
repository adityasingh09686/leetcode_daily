class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr = i*m+j;
                int k_shift = (curr+k)%(n*m);
                int nr = k_shift / m;
                int nc = k_shift % m;
                ans[nr][nc] = grid[i][j];
            }
        }

        return ans;
    }
};