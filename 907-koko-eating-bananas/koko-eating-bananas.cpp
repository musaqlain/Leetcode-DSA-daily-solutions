class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // find maximum number in piles array
        int maxNum = 0;
        for (int i=0; i<piles.size(); i++) {
            maxNum = max(maxNum, piles[i]);
        }

        int l=1, r=maxNum;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (canEatAll(piles, mid, h)) {
                r = mid;
            } else
                l = mid + 1;
        }

        return l;
    }

    int canEatAll(vector<int>& piles, int k, int h) {
        long long totalTime=0;
        for (int i=0; i<piles.size(); i++) {
            totalTime += (piles[i] + k - 1) / k;
        }

        return totalTime <= h;
    }
};