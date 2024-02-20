class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        const int size = nums.size();
        // Bubble Sort
        for (int i = 0; i < size; i++) {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (nums[j + 1] < nums[j]) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
        vector<int> res;
        for (int i=0;i<size;i++){
            if (target == nums[i]){
                res.push_back(i);
            }
        }

        return res;

    }
};