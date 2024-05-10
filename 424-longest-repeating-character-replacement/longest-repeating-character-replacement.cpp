class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26, 0);
        int maxCount = 0, maxLength = 0, start = 0;

        for (int end = 0; end < s.size(); end++) {
            hash[s[end] - 'A']++;

            maxCount = max(maxCount, hash[s[end] - 'A']);
            
            while (end - start + 1 - maxCount > k) {
                hash[s[start] - 'A']--;
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};
