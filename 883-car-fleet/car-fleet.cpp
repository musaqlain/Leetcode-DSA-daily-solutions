class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = position.size();
        vector<double> time(n);

        for (int i=0; i<n; i++) {
            time[i] = (double) (target - position[i]) / speed[i];
        }

        // sort time w.r.t position
        vector<pair<int, double>> cars;
        for (int i=0; i<n;i++) {
            cars.push_back({position[i], time[i]});
        }
        sort(cars.begin(), cars.end());

        int fleet = 0;
        double prev_time = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (cars[i].second > prev_time) { // New fleet
                prev_time = cars[i].second;
                ++fleet;
            }
        }


        return fleet;


    }
};