class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string c : strs) {
            string sorted = c;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(c);
        }

        vector<vector<string>> res;

        for (auto it : mp) {
            res.push_back(it.second);
        }
        return res;
    }
};