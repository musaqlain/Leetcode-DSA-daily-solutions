class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int longest=0;
        int start=0;

        for (int end=0; end<s.size(); ++end) {
            if (st.find(s[end]) == st.end()) {
                st.insert(s[end]);
                longest = max(longest, end-start+1);
            } else {
                while (s[start] != s[end]) {
                    st.erase(s[start]);
                    start++;
                }
                start++;
            }
        }

        return longest;
    }
};