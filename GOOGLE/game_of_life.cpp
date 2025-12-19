

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int living_neighbors = 0;

                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (dr == 0 && dc == 0)
                            continue;

                        int nr = i + dr, nc = j + dc;

                        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {

                            if (board[nr][nc] > 0) {
                                living_neighbors++;
                            }
                        }
                    }
                }

                if (board[i][j] == 1) {

                    if (living_neighbors < 2 || living_neighbors > 3) {
                        board[i][j] = 2;
                    }
                } else {

                    if (living_neighbors == 3) {
                        board[i][j] = -1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                else if (board[i][j] == -1)
                    board[i][j] = 1;
            }
        }
    }
};
