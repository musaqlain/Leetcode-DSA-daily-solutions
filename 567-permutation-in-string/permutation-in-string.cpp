class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int n1 = s1.size();
        const int n2 = s2.size();
        unordered_map<char, int> mp; 
        
        for (auto& c : s1) mp[c]++;

        for (int i = 0; i <= n2 - n1; ++i) {
            unordered_map<char, int> temp = mp; 
            int j = i + n1;

            for (int k = i; k < j; ++k) {
                if (temp[s2[k]] == 0) break;
                temp[s2[k]]--; 
                if (k == j - 1) return true;
            }
        }
        
        return false; 
    }
};
