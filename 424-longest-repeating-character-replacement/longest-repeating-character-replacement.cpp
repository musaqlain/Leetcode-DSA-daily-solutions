class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int maxFreq = 0, maxLength = 0;
        int l = 0, r = 0;

        while (r < s.size()) {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            int changes = (r - l + 1) - maxFreq;

            while (changes > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    int newMaxFreq = 0;
                    for (auto& it : mp) {
                        newMaxFreq = max(newMaxFreq, it.second);
                    }
                    maxFreq = newMaxFreq;
                }
                l++;
                changes = (r - l + 1) - maxFreq;
            }
            
            maxLength = max(maxLength, r - l + 1);
            r++;
        }

        return maxLength;
    }
};
