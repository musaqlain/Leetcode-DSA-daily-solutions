class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        set<int> st;
        vector<int> holder;

        for(auto i:nums) {
            st.insert(i);
        }

        for (auto& i:st) {
            holder.push_back(i);
        }

        if (holder.size() == 1) return 1;
        int count=1, large=1;
        for (int i=1; i<holder.size(); i++) {
            if (holder[i]-1 == holder[i-1]) {
                count++;
                large = max(large, count);
            } else {
                count = 1;
            }
        }

        return large;
    }
};