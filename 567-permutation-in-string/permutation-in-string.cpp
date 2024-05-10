class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int n1 = s1.size();
        const int n2 = s2.size();
        unordered_map<char, int> mp; // Use char instead of string for character frequency

        // Store frequency of characters in s1
        for (auto& c : s1) mp[c]++;

        for (int i = 0; i <= n2 - n1; ++i) {
            unordered_map<char, int> temp = mp; // Create a copy of mp for each window
            int j = i + n1;

            // Check if the characters in the window form a permutation of s1
            for (int k = i; k < j; ++k) {
                if (temp[s2[k]] == 0) break; // If character not in s1, move to next window
                temp[s2[k]]--; // Decrement character count
                if (k == j - 1) return true; // If all characters encountered, return true
            }
        }
        
        return false; // Return false if no permutation found
    }
};
