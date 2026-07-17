class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};

        dist[0][0] = grid[0][0];

        int V = n * n;

        for (int iter = 0; iter < V - 1; iter++) {

            bool updated = false;

            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n; col++) {

                    if (dist[row][col] == INT_MAX)
                        continue;

                    int time = dist[row][col];

                    for (int k = 0; k < 4; k++) {

                        int nr = row + dr[k];
                        int nc = col + dc[k];

                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {

                            int newTime = max(time, grid[nr][nc]);

                            if (newTime < dist[nr][nc]) {
                                dist[nr][nc] = newTime;
                                updated = true;
                            }
                        }
                    }
                }
            }

            if (!updated)
                break;
        }

        return dist[n - 1][n - 1];
    }
};