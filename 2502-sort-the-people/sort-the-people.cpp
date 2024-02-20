class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int size = heights.size();
        // selection sort
        for (int i=0;i<size;i++){
            int max = i;
            for (int j=i+1;j<size;j++){
                if (heights[max]<heights[j]) {
                    max = j;
                }
            }
            swap(heights[i], heights[max]);
            swap(names[i], names[max]);
        }

        return names;

    }
};