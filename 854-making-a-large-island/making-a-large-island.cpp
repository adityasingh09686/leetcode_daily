
class Disjoint {
public:
    vector<int> parent, rank, size;

    Disjoint(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        size.assign(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unitebyrank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY) return;

        if(rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
        else if(rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
        else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            rank[rootX]++;
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        Disjoint ds(n*n);

        int a[4] = {-1, 0, 1, 0};
        int b[4] = {0, -1, 0, 1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 0) continue;

                for(int k = 0; k < 4; k++) {
                    int x = i + a[k];
                    int y = j + b[k];

                    if(x >= 0 && x < n && y >= 0 && y < n &&
                       grid[x][y] == 1) {

                        int nodeNo = i*n + j;
                        int adjnodeNo = x*n + y;

                        ds.unitebyrank(nodeNo, adjnodeNo);
                    }
                }
            }
        }

        // Step 2: Try converting every 0 into 1
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) continue;

                set<int> components;

                for(int k = 0; k < 4; k++) {
                    int x = i + a[k];
                    int y = j + b[k];

                    if(x >= 0 && x < n && y >= 0 && y < n &&
                       grid[x][y] == 1) {

                        components.insert(ds.find(x*n + y));
                    }
                }

                int totalSize = 1;

                for(auto root : components) {
                    totalSize += ds.size[root];
                }

                maxi = max(maxi, totalSize);
            }
        }

        for(int i = 0; i < n*n; i++) {
            maxi = max(maxi, ds.size[ds.find(i)]);
        }

        return maxi;
    }
};
