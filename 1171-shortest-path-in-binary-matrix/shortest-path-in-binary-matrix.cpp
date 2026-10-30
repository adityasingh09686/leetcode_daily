class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;

        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1){
            return -1;
        }

        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};

        q.push({1,{0,0}});
        dis[0][0] = 1;

        while(!q.empty()){
            auto p = q.top();
            int d = p.first;
            int r = p.second.first;
            int c = p.second.second;
            q.pop();
            if(r == n-1 && c == m-1){
                return d;
            }

            if(d>dis[r][c]){
                continue;
            }

            for(int i=0;i<8;i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 0){
                    if(d+1 < dis[nr][nc]){
                        dis[nr][nc] = d+1;
                        q.push({dis[nr][nc],{nr,nc}});
                    }
                }
            }
        }

        return -1;
    }
};