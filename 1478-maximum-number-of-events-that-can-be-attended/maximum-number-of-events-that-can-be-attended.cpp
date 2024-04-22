// min-heap priority queue
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // sort the array based on their start day
        sort(events.begin(), events.end());
        int index = 0, result = 0, n = events.size(), day = 0;
        // min-heap priority queue
        priority_queue<int, vector<int>, greater<int>> pq;
        while (index < n || !pq.empty()) {
            if (pq.empty()) {
                day = events[index][0];
            }
            // pick up events whose start day is <= day
            while (index < n && events[index][0] <= day) {
                pq.push(events[index][1]);
                index++;
            }
            // pick up only one meeting at a given day
            pq.pop();
            result++;
            day++;
            // remove all the evebts which are expired
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }
        return result;
    }
};