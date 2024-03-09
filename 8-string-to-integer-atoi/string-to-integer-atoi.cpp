class Solution {
public:
    int myAtoi(string s) {
        const int n = s.length();

        int i = 0;
        long long int atoi = 0;
        int sign = 1;

        while (i < n && s[i] == ' ')
            i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        while (i < n && isdigit(s[i])) {
            atoi = atoi * 10;

            if (atoi<INT_MIN || atoi>INT_MAX) break;

            atoi = atoi + (s[i++] - '0');
        }

        if (sign * atoi > INT_MAX) {
            return INT_MAX;
        } else if (sign * atoi < INT_MIN) {
            return INT_MIN;
        }
        return sign * atoi;
    }
};