// this solution is based on used frequescies and unused frequencies
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for (char& c : s)
            mp[c]++;

        unordered_set<int> st;

        int deletions = 0;

        for (auto& [c, freq] : mp) {
            while (st.count(freq) && freq > 0) {
                freq--, deletions++;
            }
            if (freq > 0)
                st.insert(freq);
        }

        return deletions;
    }
};