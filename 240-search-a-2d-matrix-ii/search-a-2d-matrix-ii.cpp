class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int size = matrix.size();
        int m = 0, n = matrix[0].size() - 1;

        while (n >= 0 && m < size) {

            if (matrix[m][n] == target)
                return true;
            if (matrix[m][n] < target)
                m++;
            else
                n--;
        }

        return false;
    }
};