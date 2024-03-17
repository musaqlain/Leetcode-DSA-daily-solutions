class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();

        // create leftproduct array
        vector<int> left(n);
        vector<int> right(n);

        // left[0] = 0
        left[0] = 0;
        right[n-1] = 0;

        int holder = 1;
        // 1st loop, which starts from index 1
        for (int i=1;i<n;i++){
            // use sliding windows approach and append the last value of that array to same indexed value of leftproduct array
            holder *= nums[i-1];
            left[i] = holder;
        }

        holder = 1;
        // do same for the rigtproduct array
        for (int i = n-2; i>=0; i--) {
            holder *= nums[i+1];
            right[i] = holder;
        }

        // at last loop through that array and and add the rspective indexed element in a separat array and then return it

        left[0] = right[0];
        for (int i=1;i<n-1;i++){
            left[i]*=right[i];
        }

        return left;
    }
};