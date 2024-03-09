class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        backtrack("(", 1, 0, res, n);

        return res;
    }

private:
    void backtrack(string current, int o, int c, vector<string>& res, int n) {
        if (o == n && c == n) {
            res.push_back(current);
            return;
        }
        if (o < n)
            backtrack(current + "(", o + 1, c, res, n);
        if (c < o)
            backtrack(current + ")", o, c + 1, res, n);
    }
};