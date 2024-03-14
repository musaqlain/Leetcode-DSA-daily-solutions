class Solution {
public:
    int integerBreak(int n) {
        // n = 6

        // base cases
        if (n==2) return 1;
        if (n==3) return 2;

        int sum = 0;
        int count = 0;

        while (sum < n) {
            sum += 3, count++;
            if (sum > n) {
                sum -= 3, count--;
                break;
            }
        }
        int end = 1;
        if (n - sum == 2) {
            end = 2;
        } else if (n-sum == 1) {
            sum -= 3, count--;
            end = 4;
        }

        return pow(3, count) * end;
    }
};