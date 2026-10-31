class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto p:edges){
            int u = p[0];
            int v = p[1];
            int d = p[2];
            dist[u][v] = d;
            dist[v][u] = d;
        } 

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dist[i][j]=0;
                }
            }
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        int mini = INT_MAX;
        int ans = 0;

        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold){
                    sum++;
                }
            }
            if(sum<=mini){
                mini = sum;
                ans = i;
            }
        }

        return ans;
    }
};