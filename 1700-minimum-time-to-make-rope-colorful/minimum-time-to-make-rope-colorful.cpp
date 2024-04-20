class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int prev = 0;
        for (int i=1; i<colors.size(); i++) {
            if (colors[prev] == colors[i]) {
                if (neededTime[prev] < neededTime[i]) {
                    ans += neededTime[prev];
                    prev = i;
                } else {
                    ans += neededTime[i];
                }
            } else {
                prev = i;
            }
        }

        return ans;
    }
};