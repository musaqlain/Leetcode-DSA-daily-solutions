class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> res;

        for (string c : strs) {
            string sorted = c;
            sort(sorted.begin(), sorted.end());
            if (mp.find(sorted) != mp.end()) {
                res[mp[sorted]].push_back(c);
            } else {
                mp[sorted] = res.size();
                res.push_back({c});
            }
        }
        return res;
    }
};