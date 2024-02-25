class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        const int size = arr.size();
        int l = 0, r = size - 1;
        int mid;

        while (l <= r) {
            mid = l + (r - l) / 2;

            if ((mid > 0 && arr[mid] > arr[mid - 1]) &&
                (mid < size - 1 && arr[mid] > arr[mid + 1])) {
                return mid;
            }

            if ((mid > 0 && arr[mid] > arr[mid - 1]) ||
                (mid < size - 1 && arr[mid] < arr[mid + 1])) {
                l = mid + 1; // array slope is increasing
            } else {
                r = mid - 1; // array slope is decreasing
            }
        }

        if (arr[0]>arr[1]) return 0;
        return size - 1;
    }
};