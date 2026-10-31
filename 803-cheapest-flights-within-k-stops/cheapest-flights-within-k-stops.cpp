class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int d = flights[i][2];
            adj[u].push_back({v,d});
        }

        queue<pair<int,pair<int,int>>> q;
        vector<int> dis(n,1e9);
        q.push({0,{src,0}});
        dis[src] = 0;

        while(!q.empty()){
            auto p = q.front();
            int stops = p.first;
            int node = p.second.first;
            int cost = p.second.second;
            q.pop();
            // more than needed flights done in this path 
            if(stops>k){
                continue;
            }

            for(auto x : adj[node]) {
                int v = x.first;
                int w = x.second;

                int newCost = cost + w;

                if(newCost < dis[v]) {
                    dis[v] = newCost;
                    q.push({stops+1,{v,newCost}});
                }
            }
        }
        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};