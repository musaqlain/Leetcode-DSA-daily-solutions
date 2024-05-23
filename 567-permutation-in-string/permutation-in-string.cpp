class Solution {
private:
    bool comp(vector<int>& hashS1, vector<int>& hashS2) {
        for (int i=0; i<26; i++) {
            if (hashS1[i]!=hashS2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash1(26,0), hash2(26,0);

        for (auto& c:s1) hash1[c-'a']++;

        int i=0, j=0;
        int k=s1.size();

        while (j<s2.size()) {
            hash2[s2[j]-'a']++;
            if (j-i+1 > k) {
                hash2[s2[i]-'a']--;
                i++;
            }
            if (j-i+1 == k && comp(hash1, hash2)) return true;
            j++;
        }

        return false;
    }
};