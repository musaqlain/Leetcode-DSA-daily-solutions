class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        vector<int> prev_smaller(n, -1); // Initialize with -1
        vector<int> next_smaller(n, n); // Initialize with n
        int res = 0;

        // Find previous smaller elements
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                prev_smaller[i] = st.top();
            }
            st.push(i);
        }

        // Clear stack for next iteration
        while (!st.empty()) {
            st.pop();
        }

        // Find next smaller elements
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                next_smaller[i] = st.top();
            }
            st.push(i);
        }

        // Calculate maximum area
        for (int i = 0; i < n; ++i) {
            int area = heights[i] * (next_smaller[i] - prev_smaller[i] - 1);
            res = max(res, area);
        }

        return res;
    }
};
