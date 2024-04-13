class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> selected(26,0);
        return track(0, arr, selected, 0);
    }

    int track(int i, vector<string>& arr, vector<int>& selected, int len) {
        // base condition
        if (i==arr.size()) return len;
        string currentStr = arr[i];

        // check if the string still contains unique characters if we were to include that string too
        if (isUnique(selected, currentStr) == false) return track(i+1, arr, selected, len);
        else {
            // pick
            for (int j=0; j<currentStr.size(); j++){
                selected[currentStr[j]-'a'] = 1;
            }
            len += currentStr.size();
            int op1 = track(i+1, arr, selected, len);

            // skip
            for (int j=0; j<currentStr.size(); j++){
                selected[currentStr[j]-'a'] = 0;
            }
            len -= currentStr.size();
            int op2 = track(i+1, arr, selected, len);

            return max(op1, op2);
        }
    }

    bool isUnique(vector<int>& selected, string& currentStr) {
        // check if all the characters of currentStr are unique
        vector<int> self(26, 0);
        for (int i=0; i<currentStr.size(); i++){
            if (self[currentStr[i]-'a'] == 1) return false;
            self[currentStr[i]-'a'] = 1;
        }

        // check if all charaters are uniques if we concatenate currentStr with the previous string
        for (int i=0; i<currentStr.size(); i++){
            if (selected[currentStr[i]-'a'] == 1) return false;
        }

        return true;
    }
};