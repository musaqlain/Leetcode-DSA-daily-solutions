class Solution {
private:
    bool isPalind(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void linear(int l, int r, string& sub, string& s) {
        // Base case: if l exceeds string length, return
        if (l >= s.size()) {
            return;
        }

        // Check for palindromes starting from index l
        while (r < s.size()) {
            int length = r - l + 1;
            if (isPalind(s, l, r) && length > sub.size()) {
                sub = s.substr(l, length);
            }
            r++;
        }

        // Recursively explore next starting points
        linear(l + 1, l + 1, sub, s);
    }

public:
    string longestPalindrome(string s) {
        string sub;
        linear(0, 0, sub, s);
        return sub;
    }
};
