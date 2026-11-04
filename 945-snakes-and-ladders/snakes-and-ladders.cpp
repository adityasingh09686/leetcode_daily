class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board){
        int n = board.size();
        vector<int> vis(n*n+1,0);
        queue<pair<int,int>> q;
        q.push({1,0});
        vis[1] = 1;
        while(!q.empty()){
            auto [curr,moves] = q.front();
            q.pop();

            if(curr== n*n){
                return moves;
            }

            for(int i=1;i<=6;i++){
                int next = curr + i;

                if(next>n*n){
                    break ;
                }

                int r = (next-1)/n;
                int c = (next-1)%n;

                int row = n - 1 - r;

                if(r%2 == 1){
                    c = n - 1 - c;
                }

                if(board[row][c]!=(-1)){
                    next = board[row][c];
                }

                if(!vis[next]){
                    vis[next] = 1;
                    q.push({next,moves+1});
                }
            }
        } 

        return -1;
    }
};