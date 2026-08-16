class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> rowSet;
            unordered_set<char> columnSet;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (rowSet.count(board[i][j])) return false;
                    rowSet.insert(board[i][j]);
                }

                if (board[j][i] != '.') {
                    if (columnSet.count(board[j][i])) return false;
                    columnSet.insert(board[j][i]);
                }
            }
        }

        // 3x3 Grid Checks
        for (int blockRow = 0; blockRow < 3; blockRow++) {
            for (int blockCol = 0; blockCol < 3; blockCol++) {
                unordered_set<char> gridSet;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[blockRow * 3 + i][blockCol * 3 + j];
                        if (c != '.') {
                            if (gridSet.count(c)) return false;
                            gridSet.insert(c);
                        }
                    }
                }
            }
        }

        return true;
    }
};
