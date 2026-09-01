class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        vector<pair<int, int>> vec;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } 
                else if (classroom[i][j] == 'L') {
                    vec.push_back({i, j});
                }
            }
        }

        int k = vec.size();

        if (k == 0) return 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            auto [r, c] = vec[i];
            id[r][c] = i;
        }

        int f = (1 << k) - 1;
        vector best(
            m,
            vector(n, vector<int>(1 << k, -1))
        );

        queue<array<int, 4>> q;

        q.push({sr, sc, 0, energy});
        best[sr][sc][0] = energy;

        int moves = 0;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, remaining] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int x = r + dr[d];
                    int y = c + dc[d];

                    if (x < 0 || x >= m || y < 0 || y >= n)
                        continue;

                    if (classroom[x][y] == 'X')
                        continue;

                    int newEnergy = remaining - 1;
                    int newMask = mask;

                    if (newEnergy < 0)
                        continue;

                    if (id[x][y] != -1) {
                        newMask |= (1 << id[x][y]);
                    }
                    if (classroom[x][y] == 'R') {
                        newEnergy = energy;
                    }

                    if (newMask == f) {
                        return moves + 1;
                    }
                    if (newEnergy == 0)
                        continue;
                    if (best[x][y][newMask] >= newEnergy)
                        continue;

                    best[x][y][newMask] = newEnergy;
                    q.push({x, y, newMask, newEnergy});
                }
            }

            moves++;
        }

        return -1;
    }
};
