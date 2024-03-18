class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> combinations = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        string current;
        vector<string> answer;
        const int n = digits.size();

        if (n == 0)
            return answer;
        backtrack(0, digits, combinations, current, answer, n);
        return answer;
    }

    void backtrack(int index, string& digits,
                   unordered_map<char, string>& combinations, string& current,
                   vector<string>& answer, int n) {
        if (index == n) {
            answer.push_back(current);
            return;
        }

        char digit = digits[index];
        string letters = combinations.at(digit);

        for (auto c : letters) {
            current.push_back(c);
            backtrack(index + 1, digits, combinations, current, answer, n);
            current.pop_back();
        }
    }
};