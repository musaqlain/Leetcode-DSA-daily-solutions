class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int cols = board.size();
        int rows = board[0].size();
        int index = 0;
        for (int i=0; i<cols; i++) {
            for (int j=0; j<rows; j++) {
                if (board[i][j] == word[index]) {
                    if (search(board, i, j, word, cols, rows, index)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board,int i,int j,string& word,int cols, int rows,int index) {
        if (index == word.size()) return true;
        if (i<0||j<0||i>=cols||j>=rows||board[i][j]=='$'||board[i][j]!=word[index]) return false;

        char c = board[i][j];
        board[i][j] = '$';

        bool top = search(board, i-1, j, word, cols, rows, index+1);
        bool bottom = search(board, i+1, j, word, cols, rows, index+1);
        bool left = search(board, i, j-1, word, cols, rows, index+1);
        bool right = search(board, i, j+1, word, cols, rows, index+1);

        board[i][j] = c;
        return top||bottom||left||right;
    }
};