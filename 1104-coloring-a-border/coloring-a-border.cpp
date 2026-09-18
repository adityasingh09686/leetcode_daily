class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        int targetColor = grid[row][col]; 
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = 1;
        
        int l[4] = {-1,0,1,0};
        int r[4] = {0,1,0,-1};
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            bool isBorder = false;
            for(int i=0;i<4;i++){
                int x = p.first + l[i];
                int y = p.second + r[i];
            
                if(x < 0 || x >= n || y < 0 || y >= m || (grid[x][y] != targetColor && grid[x][y] != -color)) {
                    isBorder = true;
                }
                else if(!vis[x][y] && grid[x][y] == targetColor){
                    q.push({x,y});
                    vis[x][y] = 1;
                }
            }
            
            if (isBorder) {
                grid[p.first][p.second] = -color;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == -color){
                    grid[i][j] = color;
                }
            }
        }

        return grid;
    }
};
