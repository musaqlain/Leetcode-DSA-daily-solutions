
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2);
        unordered_set<int> hashset1(nums1.begin(), nums1.end());
        unordered_set<int> hashset2(nums2.begin(), nums2.end());

        for (auto it:hashset1) {
            if (hashset2.find(it) == hashset2.end()) answer[0].push_back(it);
        }
        for (auto it:hashset2) {
            if (hashset1.find(it) == hashset1.end()) answer[1].push_back(it);
        }

        return answer;
    }
};
