class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int it = s.size()-1;
        while (it>=0 && s[it] == ' ') it--;
        while(it>=0 && s[it] != ' ') {
            it--, count++;
        }

        return count;
    }
};