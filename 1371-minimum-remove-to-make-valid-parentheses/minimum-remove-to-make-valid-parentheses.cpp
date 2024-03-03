class Solution {
public:
    string minRemoveToMakeValid(string s) {
        const int n = s.size();
        int open =0;
        for (int i=0;i<n;i++){
            if (s[i] == '('){
                open++;
            }
            if (s[i] == ')') {
                if (open>0){
                    open--;
                } else {
                    s[i] = ' ';
                }
            }
        }

        for (int i=n-1;i>=0 && open>0;i--){
            if (s[i]=='('){
                s[i] = ' ';
                open--;
            }
        }

        s.erase(remove(s.begin(), s.end(), ' '), s.end());

        return s;
    }
};