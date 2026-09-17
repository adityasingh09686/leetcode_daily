class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int l[4] = {-1,0,1,0};
        int r[4] = {0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x = p.first + l[i];
                int y = p.second + r[i];
                if(x>=0 && x<n && y>=0 && y<m && image[x][y] == image[sr][sc] && !vis[x][y]){
                    q.push({x,y});
                    vis[x][y] = 1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]){
                    image[i][j] = color;
                }
            }
        }
        
        return image;
    }
};