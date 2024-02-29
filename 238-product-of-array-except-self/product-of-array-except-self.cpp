class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();

        vector<int> left_product(n);
        vector<int> right_product(n);

        left_product[0] = 1;
        for (int i = 1; i < n; i++) {
            left_product[i] = nums[i - 1] * left_product[i - 1];
        }

        right_product[n - 1] = 1;
        for (int j = n - 2; j >= 0; j--) {
            right_product[j] = nums[j + 1] * right_product[j + 1];
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = left_product[i] * right_product[i];
        }

        return res;
    }
};