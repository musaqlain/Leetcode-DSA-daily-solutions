class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequencyArray(26);
        for (char &ch: tasks) {
            frequencyArray[ch-'A']++;
        }
        sort(frequencyArray.begin(), frequencyArray.end(), greater<int>());

        int maxFreq = frequencyArray[0];
        int idleSlots = (maxFreq-1) * n;

        for (int i=1; i<frequencyArray.size(); i++) {
            idleSlots -= min(frequencyArray[i], maxFreq-1);
        }

        idleSlots = max(0, idleSlots);
        
        return tasks.size() + idleSlots;
    }
};