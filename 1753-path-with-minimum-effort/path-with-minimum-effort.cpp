class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid){
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;

        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        // if(grid[0][0] == 1 || grid[n-1][m-1] == 1){
        //     return -1;
        // }

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        q.push({0,{0,0}});
        dis[0][0] = 0;

        while(!q.empty()){
            auto p = q.top();
            int d = p.first;
            int r = p.second.first;
            int c = p.second.second;
            q.pop();
            if(d > dis[r][c]) continue;

            if(r == n-1 && c == m-1) {
                return d;
            }
            for(int i=0;i<4;i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int diff = abs(grid[r][c] - grid[nr][nc]);
                    int effort = max(d, diff);
                    if(effort < dis[nr][nc]) {
                        dis[nr][nc] = effort;
                        q.push({effort,{nr,nc}});
                    }
                }
            }
        }

        return dis[n-1][m-1];
    }
};