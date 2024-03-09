class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current;
        int open = 0;
        int close = 0;
        backtrack(current, open, close, res, n);

        return res;
    }

private:
    void backtrack(string& current, int o, int c, vector<string>& res, int& n) {
        if (o == n && c == n) {
            res.push_back(current);
            return;
        }
        if (o < n) {
            current.push_back('(');
            backtrack(current, o + 1, c, res, n);
            current.pop_back();
        }
        if (c < o) {
            current.push_back(')');
            backtrack(current, o, c + 1, res, n);
            current.pop_back();
        }
    }
};