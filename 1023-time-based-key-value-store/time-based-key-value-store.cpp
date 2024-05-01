class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) != mp.end()) {
            vector<pair<int, string>>& valObj = mp[key];
            int l = 0, r = valObj.size() - 1;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (valObj[mid].first == timestamp) return valObj[mid].second;
                else if (valObj[mid].first < timestamp) l = mid + 1;
                else r = mid - 1;
            }
            
            if (r >= 0) return valObj[r].second;
        }
        return "";
    }
};
