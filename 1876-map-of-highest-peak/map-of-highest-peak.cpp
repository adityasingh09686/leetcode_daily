class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> mat = isWater;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m));
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    ans[i][j]=0;
                    vis[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        int a[4] = {-1,0,1,0};
        int b[4] = {0,1,0,-1};
        int d = 0;

        while(!q.empty()){
            int l = q.front().first;
            int r = q.front().second;
            vis[l][r] = true;
            q.pop();
            for(int i=0;i<4;i++){
                int x = l + a[i];
                int y = r + b[i];
                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]){
                    ans[x][y] = ans[l][r]+1;
                    vis[x][y] = true;
                    q.push({x,y});
                }
            }
        }

        return ans;
    }
};