class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0); // to store the frequency of characters
        int maxCount = 0;  // to store the maximum frequency of any character
        int maxLength = 0; // to store the maximum length of the substring

        int start = 0; // start of the window

        for (int end = 0; end < s.size(); ++end) {
            maxCount =
                max(maxCount,
                    ++count[s[end] - 'A']); // update the frequency of the
                                            // current character and maxCount

            // if the size of the window minus the maximum frequency is greater
            // than k, we need to shrink the window from the start
            while (end - start + 1 - maxCount > k) {
                --count[s[start] -
                        'A']; // remove the character at the start of the window
                ++start;      // move the start of the window forward
            }

            maxLength = max(
                maxLength,
                end - start + 1); // update the maximum length of the substring
        }

        return maxLength;
    }
};