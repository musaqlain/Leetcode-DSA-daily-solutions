class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        int n = image.size(), m = image[0].size();
        if (oldColor == color) return image;
        fill(sr, sc, image, color, oldColor, n, m);
        return image;
    }
    void fill(int i,int j, vector<vector<int>>& image, int newColor, int oldColor, int n, int m) {
        // base condition
        // if it goes out of boundary than we will simple return
        if (i<0 || i==n || j<0 || j==m || image[i][j] != oldColor) return;

        image[i][j] = newColor;

        // left, right, top, bottom
        fill(i+1, j, image, newColor, oldColor, n, m);
        fill(i-1, j, image, newColor, oldColor, n, m);
        fill(i, j+1, image, newColor, oldColor, n, m);
        fill(i, j-1, image, newColor, oldColor, n, m);
    }
};