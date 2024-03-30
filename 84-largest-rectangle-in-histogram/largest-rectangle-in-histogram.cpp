class Solution {
private:
    vector<int> next_smaller(vector<int>& height) {
        const int n = height.size();
        vector<int> res(n, n);

        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] < height[stk.top()]) {
                res[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }

    vector<int> prev_smaller(vector<int>& height) {
        const int n = height.size();
        vector<int> res(n, -1);

        stack<int> stk;
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && height[i] < height[stk.top()]) {
                res[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> ns = next_smaller(heights);
        vector<int> ps = prev_smaller(heights);

        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int area = (ns[i] - ps[i] - 1) * heights[i];
            res = max(res, area);
        }

        return res;
    }
};
