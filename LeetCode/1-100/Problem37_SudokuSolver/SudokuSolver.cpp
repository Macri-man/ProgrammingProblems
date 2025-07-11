#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            fill(rows[i], rows[i] + 9, false);
            fill(cols[i], cols[i] + 9, false);
            fill(boxes[i], boxes[i] + 9, false);
        }

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    rows[i][num] = true;
                    cols[j][num] = true;
                    boxes[boxIndex(i, j)][num] = true;
                }
            }
        }

        backtrack(board, 0, 0);
    }

private:
    bool rows[9][9], cols[9][9], boxes[9][9];

    int boxIndex(int row, int col) {
        return (row / 3) * 3 + (col / 3);
    }

    bool backtrack(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true;
        if (col == 9) return backtrack(board, row + 1, 0);

        if (board[row][col] != '.') {
            return backtrack(board, row, col + 1);
        }

        for (int d = 0; d < 9; ++d) {
            if (!rows[row][d] && !cols[col][d] && !boxes[boxIndex(row, col)][d]) {
                board[row][col] = '1' + d;
                rows[row][d] = cols[col][d] = boxes[boxIndex(row, col)][d] = true;

                if (backtrack(board, row, col + 1)) return true;

                board[row][col] = '.';
                rows[row][d] = cols[col][d] = boxes[boxIndex(row, col)][d] = false;
            }
        }
        return false;
    }
};
