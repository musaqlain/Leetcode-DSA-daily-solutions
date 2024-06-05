class Solution {
public:
    string makeGood(string s) {
        stack<char> stck;

        for (int i=0; i<s.size(); i++) {
            if (!stck.empty() && abs(s[i] - stck.top()) == 32) {
                stck.pop();
            } else {
                stck.push(s[i]);
            }
        }

        string res;
        while (!stck.empty()) {
            res = stck.top() + res;
            stck.pop();
        }

        return res;
    }
};