class Solution {
public:
    vector<int> parent ,rank;

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unitebyrank(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY){
            if(rank[rootX] < rank[rootY]){
                parent[rootX] = rootY;
            }
            else if(rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
            }
            else{
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections){
        if(connections.size() < n-1){
            return -1;
        }

        rank.resize(n,1);
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }   
        int ans = n;

        for(auto edge:connections){
            int u = edge[0];
            int v = edge[1];

            if(find(u)!=find(v)){
                unitebyrank(u,v);
                ans--;
            }
        }

        return ans-1;
    }
};