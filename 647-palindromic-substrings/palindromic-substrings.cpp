class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.size();
        int count = 0;
        for (int i=0; i<n; i++) {
            // Even length substrings
            int l=i, r=i;
            while (l>=0 && r<=n-1 && s[l] == s[r]) {
                count++;
                l--, r++;
            }
            // Odd length substrings
            l=i, r=i+1;
            while (l>=0 && r<=n-1 && s[l] == s[r]) {
                count++;
                l--; 
                r++;
            }
        }

        return count;
    }
};