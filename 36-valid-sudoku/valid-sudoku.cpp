#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        // Check rows
        for (int i = 0; i < 9; i++) {
            st.clear();
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' &&
                    !st.insert(string(1, board[i][j])).second)
                    return false; // Duplicate found
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            st.clear();
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.' &&
                    !st.insert(string(1, board[i][j])).second)
                    return false; // Duplicate found
            }
        }

        // Check sub-grids
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                st.clear();
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        if (board[x][y] != '.' &&
                            !st.insert(string(1, board[x][y])).second)
                            return false; // Duplicate found
                    }
                }
            }
        }

        return true; // Sudoku is valid
    }
};
