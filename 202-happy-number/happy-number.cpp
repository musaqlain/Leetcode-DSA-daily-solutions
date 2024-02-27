class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;

        while (true) {
            int ans = 0;

            while (n!=0){
                int last = n%10;
                ans += last*last;
                n = n/10;
            }

            if (ans == 1)
                break;
            if (st.find(ans) != st.end())
                return false;
            st.insert(ans);
            n = ans;
        }
        return true;
    }
};