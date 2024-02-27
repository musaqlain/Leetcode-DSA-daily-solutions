class Solution {
public:
    bool isPalindrome(int x) {
        string stringX = to_string(x);
        const int size = stringX.size();

        for (int i = 0; i < size / 2; i++) {
            int j = size - i - 1;

            if (stringX[i] != stringX[j])
                return false;
        }

        return true;
    }
};