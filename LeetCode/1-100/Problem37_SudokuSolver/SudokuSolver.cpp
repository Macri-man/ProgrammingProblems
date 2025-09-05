
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int d = board[i][j] - '0';
                    int boxId = (i / 3) * 3 + j / 3;
                    row[i][d] = col[j][d] = box[boxId][d] = true;
                }
            }
        }
        backtrack(board, 0, 0);
    }

private:
    bool row[9][10] = {false};
    bool col[9][10] = {false};
    bool box[9][10] = {false};

    bool backtrack(vector<vector<char>>& board, int r, int c) {
        if (r == 9) return true; 
        if (c == 9) return backtrack(board, r + 1, 0);
        if (board[r][c] != '.') return backtrack(board, r, c + 1);

        int boxId = (r / 3) * 3 + c / 3;
        for (int d = 1; d <= 9; d++) {
            if (!row[r][d] && !col[c][d] && !box[boxId][d]) {
                board[r][c] = '0' + d;
                row[r][d] = col[c][d] = box[boxId][d] = true;

                if (backtrack(board, r, c + 1)) return true;

                board[r][c] = '.';
                row[r][d] = col[c][d] = box[boxId][d] = false;
            }
        }
        return false;  
    }
};
