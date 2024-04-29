class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int size = matrix.size();
        int m=0, n=matrix[0].size() - 1;
        int s = 0;

        while (n>=0 && m<size) {
            s = matrix[m][n];

            if (s == target) {
                return true;
            } else if (s < target) {
                m = m + 1;
            } else {
                n = n - 1;
            }
        }

        return false;
    }
};