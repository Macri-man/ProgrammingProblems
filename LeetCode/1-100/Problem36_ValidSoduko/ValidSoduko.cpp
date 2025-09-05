
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0}, col[9] = {0}, box[9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if (ch == '.') continue;

                int d = 1 << (ch - '1');
                int b = (r / 3) * 3 + (c / 3);

                if (row[r] & d || col[c] & d || box[b] & d)
                    return false;

                row[r] |= d;
                col[c] |= d;
                box[b] |= d;
            }
        }
        return true;
    }
};
