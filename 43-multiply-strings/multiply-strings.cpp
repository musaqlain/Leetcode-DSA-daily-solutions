class Solution {
public:
    string multiply(string str1, string str2) {
        if (str1 == "0" || str2 == "0") return "0";

        const int size1 = str1.size();
        const int size2 = str2.size();

        string res(size1 + size2, '0');
        const int ressize = res.size();

        for (int i = size1 - 1; i >= 0; i--) {
            for (int j = size2 - 1; j >= 0; j--) {
                int num =
                    (str1[i] - '0') * (str2[j] - '0') + (res[i + j + 1] - '0');
                res[i + j + 1] = (num % 10) + '0';
                res[i + j] += (num / 10);
            }
        }

        int i = 0;
        while (i < ressize && res[i] == '0')
            i++;

        return res.substr(i);
    }
};