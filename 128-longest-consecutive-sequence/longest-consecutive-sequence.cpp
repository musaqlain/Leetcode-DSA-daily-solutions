class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        unordered_set<int> st;
        for (int e: nums) {
            st.insert(e);
        }

        int count=1, large=1;

        for (int i:st) {
            // if it is the starting element of the sequence.
            if (st.find(i-1) == st.end()){
                count = 1;
                int x = i;

                while (st.find(x+1) != st.end()) {
                    count++, x++;
                }
            }
            large = max(large, count);
        }

        return large;
    }
};