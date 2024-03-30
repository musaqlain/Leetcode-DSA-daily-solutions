class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();

        unordered_map<int, int> mp; // value, index
        stack<int> stk;
        stk.push(nums2[n2-1]);
        vector<int> res;

        for (int i=n2-1; i>=0; i--) {
            while (!stk.empty() && nums2[i] >= stk.top()) 
                stk.pop();
            mp[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]); // value
        }

        for (int& v:nums1) {
            res.push_back(mp[v]);
        }

        return res;
    }
};