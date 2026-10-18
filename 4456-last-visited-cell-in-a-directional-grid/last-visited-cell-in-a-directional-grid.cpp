class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int a = 0, b = 0;
        int m = grid.size();
        int n = grid[0].size();

        set<pair<long long,long long>> s;
        s.insert({0, 0}); 
        int x = 0, y = 0;
        while(true){
            if(grid[x][y] == 'R'){
                y++;
            }
            else if(grid[x][y] == 'L'){
                y--;
            }
            else if(grid[x][y] == 'U'){
                x--;
            }
            else{ 
                x++;
            }
            if(x < 0 || y < 0 || x >= m || y >= n || s.contains({x,y})){
                break;
            }
            else{
                a = x;
                b = y;
            }
            s.insert({a,b});
        } 

        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);

        return ans;
    }
};
