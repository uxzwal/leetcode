class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1, totalL = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') { sr = i; sc = j; }
                else if (classroom[i][j] == 'L') totalL++;
            }
        if (totalL == 0) return 0;

        vector<vector<int>> lIdx(m, vector<int>(n, -1));
        int k = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (classroom[i][j] == 'L') lIdx[i][j] = k++;

        int fullMask = (1 << totalL) - 1;

        // dist[r][c][mask] = max energy remaining when reaching (r,c) with given mask at minimal moves
        // We use BFS; state = (r, c, mask, e). We prune dominated states by keeping max energy per (r,c,mask).
        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int>(1 << totalL, -1)));

        queue<array<int,4>> q;
        q.push({sr, sc, 0, energy});
        best[sr][sc][0] = energy;

        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto cur = q.front(); q.pop();
                int r = cur[0], c = cur[1], mask = cur[2], e = cur[3];
                if (mask == fullMask) return moves;

                for (auto &d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;

                    // Energy at current cell before moving
                    int curE = (classroom[r][c] == 'R') ? energy : e;
                    if (curE <= 0) continue; // cannot move

                    int ne = curE - 1;
                    // If landing on R, reset
                    if (classroom[nr][nc] == 'R') ne = energy;

                    int nmask = mask;
                    if (lIdx[nr][nc] != -1) nmask |= (1 << lIdx[nr][nc]);

                    if (ne > best[nr][nc][nmask]) {
                        best[nr][nc][nmask] = ne;
                        q.push({nr, nc, nmask, ne});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};