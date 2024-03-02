class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // s = "dvdf"
        int longest = 0;
        string holder;

        for (int i=0;i<s.size();i++){
            int pos = holder.find(s[i]);
            if (pos == -1) {
                holder += s[i];
                longest = max(longest, static_cast<int>(holder.size()));
            }else {
                holder.erase(0, pos+1);
                holder += s[i];
            }
        }

        return longest;
    }
};